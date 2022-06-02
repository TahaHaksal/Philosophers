#include "../Include/philo.h"

void	init_struct(t_shared_mem *ptr, char **args)
{
	ptr->num_of_philos = ft_atoi(args[0]);
	if (ptr->num_of_philos <= 0)
		exit_message("Enter a positive int for number_of_philosophers", 1);
	ptr->time_to_die = ft_atoi(args[1]);
	if (ptr->time_to_die <= 0)
		exit_message("Enter a positive int value for time_to_die", 1);
	ptr->time_to_eat = ft_atoi(args[2]);
	if (ptr->time_to_eat <= 0)
		exit_message("Enter a positive int value for time_to_eat", 1);
	ptr->time_to_sleep = ft_atoi(args[3]);
	if (ptr->time_to_sleep <= 0)
		exit_message("Enter a positive int value for time_to_sleep", 1);
}

void	init_ids(t_shared_mem *ptr, char **args)
{
	int	i;

	i = 0;
	init_struct(ptr, args);
	ptr->ids = malloc(sizeof(t_phil) * ptr->num_of_philos);
	ptr->states = malloc(ptr->num_of_philos);
	ptr->some1_died = 0;
	pthread_mutex_init(&ptr->mutex, NULL);
	while (i < ptr->num_of_philos)
	{
		ptr->ids[i].thinking = 0;
		ptr->states[i] = 0;
		ptr->ids[i].pos = i;
		ptr->ids[i].rules = ptr;
		ptr->ids[i].time_to_die = 0;
		i++;
	}
}
