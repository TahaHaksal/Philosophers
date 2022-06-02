#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct shared_mem t_shared_mem;

typedef struct phil
{
	pthread_t			thread_id;
	int					pos;
	struct shared_mem	*rules;
	char				thinking;
	int					time_to_die;
	long long			timestamp;
}						t_phil;

typedef struct shared_mem
{
	pthread_mutex_t	mutex;
	t_phil			*ids;
	int				num_of_philos;
	char			*states;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	char			some1_died;
	int				eaten_enough;
}					t_shared_mem;


//Util prototypes

int			ft_atoi(const char *str);
long long	get_timestamp();
void		exit_message(char *str, int exit_code);
void		sleep_f(int how_long);

//Init prototype

void	init_ids(t_shared_mem *ptr, char **args);

#endif
