#include <push_swap.h>

t_move	*add_move(t_move **head, t_op op)
{
	t_move	*curr;
	t_move	*new;

	new = malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	new->op = op;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (new);
}


void moves(t_stacks *stacks, int pos_a, int pos_b, t_move **moves)
{
	int size_a;
	int size_b;
	int count[4];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	size_a = stack_size(stacks->a);
	size_b = stack_size(stacks->b);
	if (pos_a < size_a / 2)
		count[0] = pos_a;
	else
		count[2] = size_a - pos_a;
	if (pos_b < size_b / 2)
		count[1] = pos_b;
	else
		count[3] = size_b - pos_b;
	while (count[0] > 0 || count[1] > 0 || count[2] > 0 || count[3] > 0)
	{
		if (count[0]-- > 0)
			op(stacks, RA, moves);
		if (count[1]-- > 0)
			op(stacks, RB, moves);
		if (count[2]-- > 0)
			op(stacks, RRA, moves);
		if (count[3]-- > 0)
			op(stacks, RRB, moves);
	}
	op(stacks, PB, moves);
}

void optimize(t_move *moves)
{
	t_move *curr;

	curr = moves;
	while (curr)
	{
		if (curr->op == RA && curr->next && curr->next->op == RB)
		{
			print_op(RR);
			curr = curr->next->next;
		}
		else if (curr->op == RRA && curr->next && curr->next->op == RRB)
		{
			print_op(RRR);
			curr = curr->next->next;
		}
		else
		{
			print_op(curr->op);
			curr = curr->next;
		}
	}
}