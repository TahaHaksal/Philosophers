/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:55:47 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 12:42:33 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

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
		pthread_mutex_lock(&ptr->rules->mutex2);
		printf("%lld %d is sleeping\n", get_timestamp(ptr->timestamp), pos);
		pthread_mutex_unlock(&ptr->rules->mutex2);
		i = -1;
		while (++i <= ptr->rules->time_to_sleep)
			sleep_f(1);
		ptr->time_to_die = ptr->rules->time_to_sleep;
		ptr->thinking = 0;
	}
}
