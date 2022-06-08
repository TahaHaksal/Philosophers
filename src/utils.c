/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:25:14 by mhaksal           #+#    #+#             */
/*   Updated: 2022/06/08 12:43:09 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	chck_neg;

	chck_neg = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		i++;
		chck_neg *= -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * chck_neg);
}

void	exit_message(char *str, int exit_code)
{
	printf("%s\n", str);
	exit(exit_code);
}

long long	get_timestamp(long long timestamp)
{
	struct timeval	tv;
	long long		now;

	gettimeofday(&tv, NULL);
	now = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (!timestamp)
		return (now);
	else
	{
		return (now - timestamp);
	}
}

void	sleep_f(int how_long)
{
	long long	timestamp;

	timestamp = get_timestamp(0);
	while (get_timestamp(0) - timestamp < how_long)
		usleep(1);
}
