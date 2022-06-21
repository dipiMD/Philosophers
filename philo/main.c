/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:24:36 by drakan            #+#    #+#             */
/*   Updated: 2022/03/13 14:29:23 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_data *philo)
{
	long	now;

	now = ft_time();
	pthread_mutex_lock(&philo->mutex_write[0]);
	if (philo->death[0] != 0)
		printf("%ld %d is eating\n", now_time(philo), philo->i + 1);
	pthread_mutex_unlock(&philo->mutex_write[0]);
	while (philo->death[0])
	{
		usleep(50);
		philo->death[0] = check_death(philo);
		if (philo->death[0] == 0)
			break ;
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
	pthread_mutex_lock(&philo->mutex_write[0]);
	if (philo->death[0] != 0)
		printf("%ld %d is sleeping\n", now_time(philo), philo->i + 1);
	pthread_mutex_unlock(&philo->mutex_write[0]);
	while (1)
	{
		usleep(100);
		if (eat_and_sleep_time(now) >= philo->time_to_sleep)
			break ;
	}
	pthread_mutex_lock(&philo->mutex_write[0]);
	if (philo->death[0] != 0)
		printf("%ld %d is thinking\n", now_time(philo), philo->i + 1);
	pthread_mutex_unlock(&philo->mutex_write[0]);
}

void	printf_philo(t_data *philo)
{
	while (philo->death[0])
	{
		pthread_mutex_lock(&philo->mutex_forks[philo->left_spoon]);
		pthread_mutex_lock(&philo->mutex_write[0]);
		if (philo->death[0] != 0)
			printf("%ld %d has taken a fork\n", now_time(philo), philo->i + 1);
		pthread_mutex_unlock(&philo->mutex_write[0]);
		pthread_mutex_lock(&philo->mutex_forks[philo->right_spoon]);
		pthread_mutex_lock(&philo->mutex_write[0]);
		if (philo->death[0] != 0)
			printf("%ld %d has taken a fork\n", now_time(philo), philo->i + 1);
		pthread_mutex_unlock(&philo->mutex_write[0]);
		if (philo->death[0] != 0)
			eat(philo);
		pthread_mutex_unlock(&philo->mutex_forks[philo->left_spoon]);
		pthread_mutex_unlock(&philo->mutex_forks[philo->right_spoon]);
		if (philo->death[0] != 0)
			sleep_philo(philo);
		if (philo->number_must_eat == 0)
			break ;
	}
}

void	*routine(void *data)
{
	t_data	philo;

	philo = *(t_data *)data;
	philo.left_spoon = philo.i;
	philo.right_spoon = ((philo.i + 1) % philo.number_of_philosophers);
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
	int		i;

	i = 0;
	memset(&data, 0, sizeof(data));
	if (parsing_to_arguments(argc, argv, &data) == 0 || \
		fork_create(&data) == 0 || philosophers_init(&data) == 0)
		return (0);
	while (data.i < data.number_of_philosophers)
	{
		pthread_create(&data.potok[data.i], NULL, routine, (void *)&data);
		usleep(10);
		data.i++;
	}
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.potok[i], NULL);
		i++;
	}
	ft_free_all(&data);
	return (0);
}
