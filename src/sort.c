/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:08 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:09 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	cost_b(int n, t_list *b, int size, t_list **best)
{
	int		cost;
	int		min;
	t_list	*curr;

	curr = b;
	min = size + 1;
	cost = 0;
	while (1)
	{
		if (n > curr->n && n < curr->prev->n && abs(cost) < min)
		{
			*best = curr;
			min = cost;
		}
		cost = cost + 1 - size * (cost > size / 2);
		curr = curr->next;
		if (curr == b)
			break ;
	}
	if (min == size + 1)
	{
		*best = get_max(b);
		min = get_node_index(b, *best);
	}
	return (min - size * (min > size / 2));
}

t_stacks	find_best(t_stacks *stacks, int size_a, int size_b, int mini)
{
	int			costs[3];
	t_stacks	curr;
	t_stacks	best;

	curr.a = stacks->a;
	costs[0] = 1;
	while (1)
	{
		costs[1] = cost_b(curr.a->n, stacks->b, size_b, &(curr.b));
		if (costs[0] * costs[1] > 0)
			costs[2] = max(abs(costs[0]), abs(costs[1]));
		else
			costs[2] = abs(costs[0]) + abs(costs[1]);
		if (costs[2] < mini)
		{
			mini = costs[2];
			best.a = curr.a;
			best.b = curr.b;
		}
		costs[0] = costs[0] + 1 - (size_a + 1) * (costs[0] > size_a / 2);
		curr.a = curr.a->next;
		if (curr.a == stacks->a)
			break ;
	}
	return (best);
}

void	sort_three(t_stacks *stacks)
{
	int	test;

	if (stacks->a == stacks->a->next->next)
		op(stacks, SA, 1);
	test = (stacks->a->n > stacks->a->next->n);
	test += (stacks->a->next->n > stacks->a->next->next->n);
	test += (stacks->a->next->next->n > stacks->a->n);
	if (test == 2)
		op(stacks, SA, 1);
	if (stacks->a->n > stacks->a->next->n)
		op(stacks, RA, 1);
	if (stacks->a->next->n > stacks->a->next->next->n)
		op(stacks, RRA, 1);
}

void	fill(t_stacks *stacks)
{
	int	count;
	int	operation;

	while (stacks->b)
	{
		count = get_node_index(stacks->a, get_next(stacks->a, stacks->b->n));
		operation = RA;
		if (count > stack_size(stacks->a) / 2)
		{
			count = abs(count - stack_size(stacks->a));
			operation = RRA;
		}
		loop_op(stacks, operation, count);
		op(stacks, PA, 1);
	}
	count = get_node_index(stacks->a, get_min(stacks->a));
	operation = RA;
	if (count > stack_size(stacks->a) / 2)
	{
		count = abs(count - stack_size(stacks->a));
		operation = RRA;
	}
	loop_op(stacks, operation, count);
}

void	sort(t_stacks *stacks)
{
	t_stacks	best;
	int			size_a;
	int			size_b;
	int			pos_a;
	int			pos_b;

	loop_op(stacks, PB, 2);
	while (stack_size(stacks->a) > 3)
	{
		size_a = stack_size(stacks->a);
		size_b = stack_size(stacks->b);
		best = find_best(stacks, size_a, size_b, size_a + size_b);
		pos_a = get_node_index(stacks->a, best.a);
		pos_b = get_node_index(stacks->b, best.b);
		moves(stacks, pos_a, pos_b);
	}
	sort_three(stacks);
	fill(stacks);
}
