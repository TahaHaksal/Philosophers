/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:27:33 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/09 13:20:49 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct shared_mem	t_shared_mem;

typedef struct phil
{
	pthread_t			thread_id;
	int					pos;
	struct shared_mem	*rules;
	char				thinking;
	long long			last_ate;
	int					ate;
	int					full;
	long long			timestamp;
}						t_phil;

typedef struct shared_mem
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex2;
	t_phil			*ids;
	int				num_of_philos;
	char			*states;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	char			some1_died;
	int				eaten_enough;
	int				ate_count;
}					t_shared_mem;

//Util prototypes

int			ft_atoi(const char *str);
long long	get_timestamp(long long timestamp);
void		exit_message(char *str, int exit_code);
void		sleep_f(int how_long);
void		print_same(t_phil *ptr, char *str);
int			most_hungry(t_phil *ptr);

//Init prototype

void		init_ids(t_shared_mem *ptr, char **args);

//Philo cycles

void		take_fork(t_phil *ptr);
void		eating(t_phil	*ptr);
void		sleeping(t_phil *ptr);
void		thinking(t_phil *ptr);

#endif
