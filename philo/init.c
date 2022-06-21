/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:27:57 by drakan            #+#    #+#             */
/*   Updated: 2022/03/11 14:52:25 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	fork_create(t_data *data)
{
	int	id;
	int	error;

	id = 0;
	data->mutex_forks = malloc(sizeof(pthread_mutex_t) * \
		data->number_of_philosophers);
	while (id < data->number_of_philosophers)
	{
		error = pthread_mutex_init(&data->mutex_forks[id], NULL);
		if (error != 0)
		{
			ft_putstr("Error init fork");
			return (0);
		}
		id++;
	}
	data->mutex_write = malloc(sizeof(pthread_mutex_t));
	error = pthread_mutex_init(&data->mutex_write[0], NULL);
	if (error != 0)
	{
		ft_putstr("Error init fork");
		return (0);
	}
	return (1);
}

int	philosophers_init(t_data *data)
{
	data->i = 0;
	data->start_time = ft_time();
	data->death = malloc(sizeof(int));
	data->death[0] = 1;
	data->potok = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	if (!data->potok || !data->death)
	{
		ft_putstr("Error malloc");
		return (0);
	}
	return (1);
}
