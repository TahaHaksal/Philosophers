/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_hungry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:24:41 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/09 13:24:43 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

int	most_hungry(t_phil *ptr)
{
	t_phil	*r;
	int		temp;
	int		num;
	int		i;

	i = 0;
	num = ptr->rules->num_of_philos;
	r = ptr->rules->ids;
	temp = 0;
	while (i < num)
	{
		if (temp < get_timestamp(r[i].last_ate))
			temp = get_timestamp(r[i].last_ate);
		i++;
	}
	if (temp <= get_timestamp(r[ptr->pos].last_ate))
		return (1);
	else
		return (0);
}
