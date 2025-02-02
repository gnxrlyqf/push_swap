#include <push_swap.h>

void swap(t_list **stack)
{
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->next->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
}

void push(t_list **s1, t_list **s2)
{
	t_list *prev;
	t_list *next;

	prev = (*s1)->prev;
	next = (*s1)->next;
	prev->next = next;
	next->prev = prev;
	(*s1)->next = *s2;
	(*s1)->prev = (*s2)->prev;
	(*s2)->prev->next = *s1;
	(*s2)->prev = *s1;
	*s2 = *s1;
	*s1 = next;
}

void rotate(t_list **stack, int rev)
{
	if (!rev)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
}

void op(t_stacks *s, t_op op)
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
		push(&(s->a), &(s->b));
	if (op == PB)
		push(&(s->b), &(s->a));
	if (op == RA || op == RRA)
		rotate(&(s->a), RRA - op);
	if (op == RB || op == RRB)
		rotate(&(s->b), RRB - op);
	if (op == RR || op == RRR)
	{
		rotate(&(s->a), RRR - op);
		rotate(&(s->b), RRR - op);
	}
}
