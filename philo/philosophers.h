/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:23:41 by drakan            #+#    #+#             */
/*   Updated: 2022/03/12 19:56:25 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_must_eat;
	int				left_spoon;
	int				count_eating;
	int				right_spoon;
	int				i;
	int				*death;
	long			start_time;
	long			time_die;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutex_write;
	pthread_t		*potok;
}	t_data;

int		check_death(t_data *philo);
void	ft_free_all(t_data *data);
int		parsing_to_arguments(int argc, char **argv, t_data *data);
int		fork_create(t_data *data);
int		philosophers_init(t_data *data);
size_t	now_time(t_data *philo);
long	eat_and_sleep_time(long time);
long	ft_time(void);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

#endif