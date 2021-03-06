/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:54:38 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 19:06:53 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	eating(t_phil	*ptr)
{
	int	pos;

	pos = ptr->pos;
	if (ptr->rules->states[pos])
	{
		ptr->last_ate = get_timestamp(0);
		print_same(ptr, "is eating");
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
