/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:53:12 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 12:48:01 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	take_fork(t_phil *ptr)
{
	int		pos;
	int		n;
	int		left;
	int		right;
	char	*states;

	pos = ptr->pos;
	n = ptr->rules->num_of_philos;
	left = (pos - 1 + n) % n;
	right = (pos + 1) % n;
	states = ptr->rules->states;
	if (ptr->rules->num_of_philos < 2)
		return ;
	pthread_mutex_lock(&ptr->rules->mutex);
	if (!states[pos] && !states[left] && !states[right])
	{
		states[pos] = 1;
		pthread_mutex_lock(&ptr->rules->mutex2);
		printf("%lld %d has taken a fork\n", get_timestamp(ptr->timestamp), pos);
		printf("%lld %d has taken a fork\n", get_timestamp(ptr->timestamp), pos);
		pthread_mutex_unlock(&ptr->rules->mutex2);
	}
	pthread_mutex_unlock(&ptr->rules->mutex);
}
