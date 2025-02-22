/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:04:54 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:04:59 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check(char c)
{
	if (c == ' ' || c == '\0')
		return (-1);
	if (c == '+' || c == '-')
		return (0);
	if (c >= 48 && c <= 57)
		return (1);
	return (2);
}

int	validate_input(char **av)
{
	char	*s;

	while (*av)
	{
		if (!**av)
			return (0);
		s = *av;
		while (*s)
		{
			if (check(*s) == 2 || (!check(*s) && !check(*(s + 1)))
				|| check(*s) - check(*(s + 1)) == 1)
				return (0);
			s++;
		}
		av++;
	}
	return (1);
}
