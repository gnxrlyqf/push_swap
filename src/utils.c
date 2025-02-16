#include <push_swap.h>

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign *= (44 - *str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int same_sign(int a, int b)
{
	if (a * b > 0)
		return (1);
	return (0);
}