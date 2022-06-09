/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:53:12 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 19:09:39 by mhaksal          ###   ########.fr       */
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
		print_same(ptr, "has taken a fork");
		print_same(ptr, "has taken a fork");
	}
	pthread_mutex_unlock(&ptr->rules->mutex);
}
