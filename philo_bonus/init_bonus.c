/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:27:57 by drakan            #+#    #+#             */
/*   Updated: 2022/03/12 19:42:47 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	philosophers_init(t_data *data)
{
	data->i = 0;
	data->start_time = ft_time();
	data->potok = malloc(sizeof(int) * data->number_of_philosophers);
	memset(data->potok, 0, data->number_of_philosophers);
	if (!data->potok)
	{
		ft_putstr("Error malloc");
		return (0);
	}
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/death");
	data->forks = sem_open("/forks", O_CREAT, 644, \
		data->number_of_philosophers);
	data->write = sem_open("/write", O_CREAT, 644, 1);
	data->death = sem_open("/death", O_CREAT, 644, 1);
	return (1);
}
