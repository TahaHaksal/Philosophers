/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:56:24 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/09 13:30:24 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	thinking(t_phil *ptr)
{
	long long	timestamp;

	while (!ptr->rules->states[ptr->pos])
	{
		if (most_hungry(ptr))
			take_fork(ptr);
		if (!ptr->rules->states[ptr->pos])
		{
			if (get_timestamp(ptr->last_ate) >= ptr->rules->time_to_die)
			{
				timestamp = get_timestamp(ptr->timestamp);
				pthread_mutex_lock(&ptr->rules->mutex2);
				printf("%lld %d died\n", timestamp, ptr->pos + 1);
				exit(0);
			}
			sleep_f(1);
		}
	}
}
