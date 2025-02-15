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

	size_a = stack_size(stacks->a);
	size_b = stack_size(stacks->b);

	if (pos_a < size_a / 2)
		loop_op(stacks, RA, pos_a, moves);
	else
		loop_op(stacks, RRA, abs(pos_a - size_a), moves);
	if (pos_b < size_b / 2)
		loop_op(stacks, RB, pos_b, moves);
	else
		loop_op(stacks, RRB, abs(pos_b - size_b), moves);
	op(stacks, PB, moves);
}
