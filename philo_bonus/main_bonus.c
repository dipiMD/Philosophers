/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:24:36 by drakan            #+#    #+#             */
/*   Updated: 2022/03/12 19:53:22 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eat(t_data *philo)
{
	long	now;

	now = ft_time();
	sem_wait(philo->write);
	printf("%ld %d is eating\n", now_time(philo), philo->i + 1);
	sem_post(philo->write);
	while (1)
	{
		usleep(50);
		check_death(philo);
		if (eat_and_sleep_time(now) >= philo->time_to_eat)
			break ;
	}
	now = ft_time();
	philo->time_die = now + philo->time_to_die;
	philo->number_must_eat--;
}

void	sleep_philo(t_data *philo)
{
	long	now;

	now = ft_time();
	sem_wait(philo->write);
	printf("%ld %d is sleeping\n", now_time(philo), philo->i + 1);
	sem_post(philo->write);
	while (1)
	{
		usleep(50);
		if (eat_and_sleep_time(now) >= philo->time_to_sleep)
			break ;
	}
	sem_wait(philo->write);
	printf("%ld %d is thinking\n", now_time(philo), philo->i + 1);
	sem_post(philo->write);
}

void	printf_philo(t_data *philo)
{
	while (1)
	{
		sem_wait(philo->forks);
		printf("%ld %d has taken a fork\n", now_time(philo), philo->i + 1);
		usleep(50);
		sem_wait(philo->forks);
		printf("%ld %d has taken a fork\n", now_time(philo), philo->i + 1);
		eat(philo);
		sem_post(philo->forks);
		sem_post(philo->forks);
		sleep_philo(philo);
		if (philo->number_must_eat == 0)
		{
			sem_wait(philo->death);
			exit(1);
		}
	}
}

void	*routine(void *data)
{
	t_data	philo;

	philo = *(t_data *)data;
	philo.time_die = philo.start_time + philo.time_to_die;
	philo.start_time = ft_time();
	if (philo.i % 2 == 1)
		usleep(1000);
	printf_philo(&philo);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (parsing_to_arguments(argc, argv, &data) == 0 || \
		philosophers_init(&data) == 0)
		return (0);
	while (data.i < data.number_of_philosophers)
	{
		data.potok[data.i] = fork();
		if (data.potok[data.i] == 0)
			routine(&data);
		data.i++;
	}
	ft_free_all(&data);
	return (0);
}
