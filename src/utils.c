/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:14 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:16 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long	ft_atoi_ptr(char **str)
{
	int		sign;
	long	result;
	char	*cpy;

	result = 0;
	sign = 1;
	cpy = *str;
	while (*cpy == ' ' || (*cpy >= 9 && *cpy <= 13))
		cpy++;
	if (*cpy == '-' || *cpy == '+')
		sign *= (44 - *cpy++);
	while (*cpy >= '0' && *cpy <= '9')
	{
		result = result * 10 + (*cpy++ - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (result * sign);
	}
	while (*cpy && *cpy == ' ')
		cpy++;
	*str = cpy;
	return (result * sign);
}

int	min(int a, int b)
{
	return (a * (a < b) + b * (a >= b));
}

int	max(int a, int b)
{
	return (a * (a >= b) + b * (a < b));
}

int	abs(int n)
{
	return (n * (n >= 0) - n * (n < 0));
}

void	throw_err(t_list *stack)
{
	t_list	*curr;

	if (stack)
	{
		curr = stack;
		while (curr->next)
			curr = curr->next;
		curr->next = stack;
	}
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
