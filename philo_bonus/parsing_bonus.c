/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:04:44 by drakan            #+#    #+#             */
/*   Updated: 2022/03/12 19:45:56 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	parsing2(int argc, t_data *data)
{
	if (data->number_of_philosophers < 1 || data->time_to_die < 1 || \
			data->time_to_eat < 1 || data->time_to_sleep < 1 || \
					data->number_of_philosophers > 200)
	{
		ft_putstr ("Invalid arguments");
		return (0);
	}
	if (argc == 6)
	{
		if (data->number_must_eat <= 0)
		{
			ft_putstr("Invalid arguments");
			return (0);
		}
	}
	return (1);
}

int	parsing_to_arguments(int argc, char **argv, t_data *data)
{
	if (argc >= 5 && argc <= 6)
	{
		data->number_of_philosophers = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->number_must_eat = ft_atoi(argv[5]);
	}
	else
	{
		ft_putstr("Error arguments");
		return (0);
	}
	if (parsing2(argc, data) == 0)
		return (0);
	if (data->number_of_philosophers == 1)
	{
		data->start_time = ft_time();
		usleep(1000);
		printf("%ld 1 is dead\n", now_time(data));
		return (0);
	}
	return (1);
}
