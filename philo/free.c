/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:36 by drakan            #+#    #+#             */
/*   Updated: 2022/03/12 19:56:18 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->mutex_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_write[0]);
	free(data->mutex_write);
	free(data->death);
	free(data->potok);
}
