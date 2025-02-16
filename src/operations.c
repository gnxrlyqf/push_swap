#include <push_swap.h>

void swap(t_list **stack)
{
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->next->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
}

void push(t_list **s1, t_list **s2)
{
	t_list *to_push;
	t_list *prev;
	t_list *next;

	if (!s1 || !*s1)
		return;
	to_push = *s1;
	if (*s1 == (*s1)->next)
		*s1 = NULL;
	else
	{
		prev = to_push->prev;
		next = to_push->next;
		prev->next = next;
		next->prev = prev;
		*s1 = next;
	}
	if (!s2 || !*s2)
	{
		to_push->next = to_push;
		to_push->prev = to_push;
		*s2 = to_push;
	}
	else
	{
		to_push->next = *s2;
		to_push->prev = (*s2)->prev;
		(*s2)->prev->next = to_push;
		(*s2)->prev = to_push;
		*s2 = to_push;
	}
}

void rotate(t_list **stack, int rev)
{
	if (!rev)
		*stack = (*stack)->prev;
	else
		*stack = (*stack)->next;
}

void op(t_stacks *s, t_op op, t_move **moves)
{
	if (op == SA)
		swap(&(s->a));
	if (op == SB)
		swap(&(s->b));
	if (op == SS)
	{
		swap(&(s->a));
		swap(&(s->b));
	}
	if (op == PA)
		push(&(s->b), &(s->a));
	if (op == PB)
		push(&(s->a), &(s->b));
	if (op == RA || op == RRA)
		rotate(&(s->a), RRA - op);
	if (op == RB || op == RRB)
		rotate(&(s->b), RRB - op);
	if (op == RR || op == RRR)
	{
		rotate(&(s->a), RRR - op);
		rotate(&(s->b), RRR - op);
	}
	add_move(moves, op);
}

void print_op(t_op op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	if (op == SB)
		write(1, "sb\n", 3);
	if (op == SS)
		write(1, "ss\n", 3);
	if (op == PA)
		write(1, "pa\n", 3);
	if (op == PB)
		write(1, "pb\n", 3);
	if (op == RA)
		write(1, "ra\n", 3);
	if (op == RB)
		write(1, "rb\n", 3);
	if (op == RR)
		write(1, "rr\n", 3);
	if (op == RRA)
		write(1, "rra\n", 4);
	if (op == RRB)
		write(1, "rrb\n", 4);
	if (op == RRR)
		write(1, "rrr\n", 4);
}

void loop_op(t_stacks *s, t_op opcode, int count, t_move **moves)
{
	while (count--)
		op(s, opcode, moves);
}