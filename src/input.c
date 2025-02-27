/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:04:54 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/27 18:51:22 by mchetoui         ###   ########.fr       */
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
	int		found;

	while (*av)
	{
		s = *av;
		found = 0;
		while (*s)
		{
			if (check(*s) == 1)
				found = 1;
			if (check(*s) == 2 || (!check(*s) && !check(*(s + 1)))
				|| check(*s) - check(*(s + 1)) == 1)
				return (0);
			s++;
		}
		if (!found)
			return (0);
		av++;
	}
	return (1);
}

t_stacks	init_stack(char **av)
{
	char		*str;
	t_stacks	stacks;
	t_list		*prev;
	t_list		*new;
	long		n;

	stacks.a = NULL;
	str = *av++;
	while (str && *str)
	{
		n = ft_atoi_ptr(&str);
		if (!*str)
			str = *av++;
		if (n > INT_MAX || n < INT_MIN || find_node(stacks.a, (int)n))
			throw_err(stacks.a);
		new = add_node(&stacks.a, (int)n);
		new->prev = prev;
		prev = new;
	}
	new->next = stacks.a;
	stacks.a->prev = new;
	stacks.b = NULL;
	return (stacks);
}
