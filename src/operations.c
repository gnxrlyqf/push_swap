/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:06 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:07 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list **stack)
{
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->next->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
}

void	push(t_list **s1, t_list **s2, t_list *temp)
{
	if (!s1 || !*s1)
		return ;
	temp = *s1;
	if (*s1 == (*s1)->next)
		*s1 = NULL;
	else
	{
		*s1 = temp->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	if (!*s2)
	{
		temp->prev = temp;
		temp->next = temp->prev;
	}
	else
	{
		temp->next = *s2;
		temp->prev = (*s2)->prev;
		(*s2)->prev->next = temp;
		(*s2)->prev = temp;
	}
	*s2 = temp;
}

void	rotate(t_list **stack, int rev)
{
	if (!rev)
		*stack = (*stack)->prev;
	else
		*stack = (*stack)->next;
}

void	op(t_stacks *s, t_op op)
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
		push(&(s->b), &(s->a), NULL);
	if (op == PB)
		push(&(s->a), &(s->b), NULL);
	if (op == RA || op == RRA)
		rotate(&(s->a), RRA - op);
	if (op == RB || op == RRB)
		rotate(&(s->b), RRB - op);
	if (op == RR || op == RRR)
	{
		rotate(&(s->a), RRR - op);
		rotate(&(s->b), RRR - op);
	}
	print_op(op);
}

void	print_op(t_op op)
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
