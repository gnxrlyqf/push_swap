#include <push_swap.h>

int calc_cost_b(int n, t_list *b, int size, t_list **best)
{
	int cost;
	int min;
	t_list *curr;

	curr = b;
	min = size;
	cost = 0;
	while (1)
	{
		if (n > curr->n && n < curr->prev->n && cost < min)
		{
			min = cost;
			*best = curr;
		}
		cost -= size * (cost > size / 2);
		cost++;
		curr = curr->next;
		if (curr == b)
			break ;
	}
	if (min == size)
	{
		*best = get_max(b);
		cost = get_node_index(b, *best);
		cost -= size * (cost > size / 2);
	}
	return (cost);
}

t_stacks find_best(t_stacks *stacks, int size_a, int size_b)
{
	int min;
	int cost;
	int moves;
	t_stacks curr;
	t_stacks best;

	curr.a = stacks->a;
	min = size_a + 1;
	moves = 1;
	while (1)
	{
		cost = abs(moves - calc_cost_b(curr.a->n, stacks->b, size_b, &(curr.b)));
		if (cost < min)
		{
			min = cost;
			best.a = curr.a;
			best.b = curr.b;
		}
		moves -= (size_a + 1) * (moves > size_a / 2);
		moves++;
		curr.a = curr.a->next;
		if (curr.a == stacks->a)
			break ;
	}
	return (best);
}

void	sort_three(t_stacks *stacks, t_move **movelist)
{
	if (stacks->a->n > stacks->a->next->n)
		op(stacks, SA, movelist);
	while (stacks->a->next->n > stacks->a->next->next->n)
	{
		op(stacks, RRA, movelist);
		op(stacks, SA, movelist);
	}
}

void fill(t_stacks *stacks, t_move **movelist)
{
	int count;
	int operation;

	while (stacks->b)
	{
		count = get_node_index(stacks->a, get_next(stacks->a, stacks->b->n));
		operation = RA;
		if (count > stack_size(stacks->a) / 2)
		{
			count = abs(count - stack_size(stacks->a));
			operation = RRA;
		}
		loop_op(stacks, operation, count, movelist);
		op(stacks, PA, movelist);
	}
	count = get_node_index(stacks->a, get_min(stacks->a));
	operation = RA;
	if (count > stack_size(stacks->a) / 2)
	{
		count = abs(count - stack_size(stacks->a));
		operation = RRA;
	}
	loop_op(stacks, operation, count, movelist);
}

void sort(t_stacks *stacks)
{
	t_move *movelist;
	t_stacks best;
	int pos_a;
	int pos_b;

	movelist = NULL;
	op(stacks, PB, &movelist);
	op(stacks, PB, &movelist);
	while (stack_size(stacks->a) > 3)
	{
		best = find_best(stacks, stack_size(stacks->a), stack_size(stacks->b));
		pos_a = get_node_index(stacks->a, best.a);
		pos_b = get_node_index(stacks->b, best.b);
		moves(stacks, pos_a, pos_b, &movelist);
	}
	sort_three(stacks, &movelist);
	fill(stacks, &movelist);
	optimize(movelist);
}