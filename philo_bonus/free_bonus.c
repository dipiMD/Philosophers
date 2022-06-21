/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:47:36 by drakan            #+#    #+#             */
/*   Updated: 2022/03/12 20:08:01 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_free_all(t_data *data)
{
	int		i;
	int		pid;

	i = 0;
	waitpid(-1, &pid, 0);
	if (pid != 0)
	{
		while (i < data->number_of_philosophers)
		{
			kill(data->potok[i], SIGTERM);
			i++;
		}
	}
	free(data->potok);
	sem_unlink("/fork");
	sem_unlink("/write");
	sem_unlink("/death");
	sem_close(data->forks);
	sem_close(data->write);
	sem_close(data->death);
}
