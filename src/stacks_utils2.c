/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:10 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:11 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*get_node(t_list *stack, int index)
{
	t_list	*curr;

	curr = stack;
	while (1)
	{
		if (!index)
			break ;
		curr = curr->next;
		index--;
	}
	return (curr);
}

t_list	*get_max(t_list *stack)
{
	t_list	*out;
	t_list	*curr;
	int		max;

	curr = stack;
	out = curr;
	max = 0;
	while (1)
	{
		if (curr->n > max)
		{
			out = curr;
			max = curr->n;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (out);
}

t_list	*get_min(t_list *stack)
{
	t_list	*out;
	t_list	*curr;
	int		min;

	curr = stack;
	out = curr;
	min = stack->n;
	while (1)
	{
		if (curr->n < min)
		{
			out = curr;
			min = curr->n;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (out);
}

t_list	*get_next(t_list *stack, int n)
{
	int		min;
	t_list	*next;
	t_list	*curr;

	next = NULL;
	min = get_max(stack)->n;
	if (n > min)
		return (get_min(stack));
	curr = stack;
	while (1)
	{
		if (curr->n > n && curr->n - n < min)
		{
			next = curr;
			min = curr->n - n;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (next);
}

int	get_index(t_list *stack, t_list *node)
{
	t_list	*curr;
	int		index;

	curr = stack;
	index = 0;
	while (1)
	{
		if (curr == node)
			break ;
		curr = curr->next;
		index++;
		if (curr == stack)
			break ;
	}
	return (index);
}
