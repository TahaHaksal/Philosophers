#include "../Include/philo.h"

void	take_fork(t_phil *ptr)
{
	int		pos;
	int		N;
	int		left;
	int		right;
	char	*states;

	pos = ptr->pos;
	N = ptr->rules->num_of_philos;
	left = (pos - 1 + N) % N;
	right = (pos + 1) % N;
	states = ptr->rules->states;
	pthread_mutex_lock(&ptr->rules->mutex);
	if (!states[pos] && !states[left] && !states[right])
	{
		states[pos] = 1;
		printf("%d %d has taken a fork\n", get_timestamp() - ptr->timestamp, pos);
		printf("%d %d has taken a fork\n", get_timestamp() - ptr->timestamp, pos);
	}
	pthread_mutex_unlock(&ptr->rules->mutex);
}

void	eating(t_phil	*ptr)
{
	int	pos;

	pos = ptr->pos;
	if (ptr->rules->states[pos])
	{
		printf("%d %d is eating\n", get_timestamp() - ptr->timestamp, pos);
		sleep_f(ptr->rules->time_to_eat);
	}
}

void	sleeping(t_phil *ptr)
{
	int	pos;
	int	i;

	pos = ptr->pos;
	if (ptr->rules->states[pos])
	{
		pthread_mutex_lock(&ptr->rules->mutex);
		ptr->rules->states[pos] = 0;
		pthread_mutex_unlock(&ptr->rules->mutex);
		ptr->time_to_die = 0;
		printf("%d %d is sleeping\n", get_timestamp() - ptr->timestamp, pos);
		i = 0;
		while(i < ptr->rules->time_to_sleep)
		{
			sleep_f(1);
			ptr->time_to_die++;
			if (ptr->rules->time_to_die <= ptr->time_to_die)
			{
				printf("%d %d died\n", get_timestamp() - ptr->timestamp, pos);
				exit(0);
			}
		}
		ptr->thinking = 0;
	}
}

void	thinking(t_phil *ptr)
{
	if (ptr->rules->time_to_die > ptr->time_to_die)
	{
		if (!ptr->thinking)
		{
			ptr->thinking = 1;
			printf("%d %d is thinking\n", get_timestamp() - ptr->timestamp, ptr->pos);
		}
		ptr->time_to_die++;
		sleep_f(1);
	}
	else
	{
		printf("%d %d died\n", get_timestamp() - ptr->timestamp, ptr->pos);
		exit(0);
	}
}

void	*deneme(void *arg)
{
	t_phil	*ptr;

	ptr = (t_phil *)arg;
	ptr->timestamp = get_timestamp();
	while (1)
	{
		take_fork(ptr);
		eating(ptr);
		sleeping(ptr);
		thinking(ptr);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_shared_mem	main_struct;

	if (ac != 5 && ac != 6)
		exit_message("This program can handle 4 or 5 arguments", 1);
	init_ids(&main_struct, &av[1]);
	for(int	i = 0; i < main_struct.num_of_philos; i++)
	{
		pthread_create(&main_struct.ids[i].thread_id, NULL, &deneme, &main_struct.ids[i]);
	}
	for (int	i = 0; i < main_struct.num_of_philos; i++)
	{
		pthread_join(main_struct.ids[i].thread_id, NULL);
	}
	pthread_mutex_destroy(&main_struct.mutex);
	exit(0);
}
