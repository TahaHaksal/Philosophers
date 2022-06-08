/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:54:38 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 12:42:55 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	eating(t_phil	*ptr)
{
	int	pos;

	pos = ptr->pos;
	if (ptr->rules->states[pos])
	{
		pthread_mutex_lock(&ptr->rules->mutex2);
		printf("%lld %d is eating\n", get_timestamp(ptr->timestamp), pos);
		pthread_mutex_unlock(&ptr->rules->mutex2);
		sleep_f(ptr->rules->time_to_eat);
		if (ptr->ate < ptr->rules->eaten_enough)
			ptr->ate++;
		else if (!ptr->full)
		{
			ptr->rules->ate_count++;
			ptr->full++;
		}
	}
}
