/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_opeation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:05:56 by drakan            #+#    #+#             */
/*   Updated: 2022/03/12 19:46:02 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	ft_time(void)
{
	struct timeval	start_time;
	long			res;

	gettimeofday(&start_time, NULL);
	res = (1000 * start_time.tv_sec) + (start_time.tv_usec / 1000);
	return (res);
}

size_t	now_time(t_data *philo)
{
	struct timeval	curr_time;
	long			now;

	gettimeofday(&curr_time, NULL);
	now = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (now - philo->start_time);
}

long	eat_and_sleep_time(long time)
{
	struct timeval	curr_time;
	long			now;

	gettimeofday(&curr_time, NULL);
	now = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (now - time);
}
