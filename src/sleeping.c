/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:55:47 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/09 13:01:36 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	sleeping(t_phil *ptr)
{
	int			pos;
	long long	i;

	pos = ptr->pos;
	if (ptr->rules->states[pos])
	{
		print_same(ptr, "is sleeping");
		pthread_mutex_lock(&ptr->rules->mutex);
		ptr->rules->states[pos] = 0;
		pthread_mutex_unlock(&ptr->rules->mutex);
		i = get_timestamp(0);
		while (get_timestamp(0) - i < ptr->rules->time_to_sleep)
		{
			if (get_timestamp(ptr->last_ate) >= ptr->rules->time_to_die)
			{
				pthread_mutex_lock(&ptr->rules->mutex2);
				printf("%lld %d died\n", get_timestamp(ptr->timestamp), pos);
				exit(0);
			}
			sleep_f(1);
		}
		print_same(ptr, "is thinking");
	}
}
