/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:50:19 by drakan            #+#    #+#             */
/*   Updated: 2022/03/13 14:20:29 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int						i;
	int						k;
	long long unsigned int	j;

	k = 1;
	i = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - 48);
		i++;
	}
	if (j >= __LONG_MAX__ && k == -1)
		return (0);
	if (j >= __LONG_MAX__ && k == 1)
		return (-1);
	return (k * j);
}

int	check_death(t_data *philo)
{
	long	now;
	int		i;

	i = 0;
	now = ft_time();
	if (now - philo->time_die > 0)
	{
		pthread_mutex_lock(&philo->mutex_write[0]);
		if (philo->death[0])
			printf("%ld %d is dead\n", now_time(philo) - 1, philo->i + 1);
		philo->death[0] = 0;
		pthread_mutex_unlock(&philo->mutex_write[0]);
		return (0);
	}
	return (1);
}
