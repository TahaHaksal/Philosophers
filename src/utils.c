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

long long	get_timestamp()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleep_f(int how_long)
{
	long long timestamp;

	timestamp = get_timestamp();
	while (get_timestamp() - timestamp != how_long)
		usleep(1);
}
