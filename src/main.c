/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:24:53 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 19:05:04 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	*loop(void *arg)
{
	t_phil			*ptr;
	t_shared_mem	*rules;

	ptr = (t_phil *)arg;
	rules = ptr->rules;
	ptr->last_ate = get_timestamp(0);
	while (1)
	{
		if (rules->ate_count >= rules->num_of_philos && rules->eaten_enough)
		{
			pthread_mutex_lock(&ptr->rules->mutex2);
			printf("Everyone is full\n");
			exit(0);
		}
		thinking(ptr);
		eating(ptr);
		sleeping(ptr);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_shared_mem	main_struct;
	t_phil			*ids;
	int				i;

	if (ac != 5 && ac != 6)
		exit_message("This program can handle 4 or 5 arguments", 1);
	init_ids(&main_struct, &av[1]);
	ids = main_struct.ids;
	i = 0;
	while (i < main_struct.num_of_philos)
	{
		pthread_create(&ids[i].thread_id, NULL, &loop, &ids[i]);
		i++;
	}
	i = 0;
	while (i < main_struct.num_of_philos)
	{
		pthread_join(ids[i].thread_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&main_struct.mutex);
	pthread_mutex_destroy(&main_struct.mutex2);
	exit(0);
}
