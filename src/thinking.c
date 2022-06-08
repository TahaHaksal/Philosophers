/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:56:24 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 12:58:56 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	thinking(t_phil *ptr)
{
	long long	timestamp;

	timestamp = get_timestamp(ptr->timestamp);
	if (ptr->first)
	{
		ptr->first = 0;
		return ;
	}
	if (!ptr->thinking)
	{
		ptr->thinking = 1;
		pthread_mutex_lock(&ptr->rules->mutex2);
		printf("%lld %d is thinking\n", timestamp, ptr->pos);
		pthread_mutex_unlock(&ptr->rules->mutex2);
	}
	printf("time_to_die count %d for pos: %d\n", ptr->time_to_die, ptr->pos);
	sleep_f(1);
	ptr->time_to_die++;
	if (ptr->time_to_die >= ptr->rules->time_to_die)
	{
		pthread_mutex_lock(&ptr->rules->mutex2);
		printf("%lld %d died\n", timestamp, ptr->pos);
		exit(0);
		pthread_mutex_unlock(&ptr->rules->mutex2);
	}
}
