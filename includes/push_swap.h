/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:08:16 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 18:08:18 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				n;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

typedef enum e_op
{
	NONE,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_op;

typedef struct s_move
{
	t_op			op;
	struct s_move	*next;
}	t_move;

void		swap(t_list **stack);
void		push(t_list **s1, t_list **s2, t_list *temp);
void		rotate(t_list **stack, int rev);
t_op		op(t_stacks *s, t_op op, int print);
t_stacks	init_stack(char **av);
t_list		*add_node(t_list **head, int n);
int			stack_size(t_list *stack);
long		ft_atoi_ptr(char **str);
int			cost_b(int n, t_list *b, int size, t_list **best);
t_stacks	find_best(t_stacks *stacks, int size_a, int size_b, int mini);
int			min(int a, int b);
void		sort(t_stacks *stacks);
void		moves(t_stacks *stacks, int pos_a, int pos_b);
t_list		*get_node(t_list *stack, int index);
int			get_index(t_list *stack, t_list *node);
t_list		*get_max(t_list *stack);
t_list		*get_min(t_list *stack);
t_list		*get_next(t_list *stack, int n);
void		loop_op(t_stacks *s, t_op opcode, int count);
void		print_op(t_op op);
int			max(int a, int b);
int			validate_input(char **av);
t_list		*find_node(t_list *stack, int n);
void		throw_err(t_list *stack, int f);
void		sort_three(t_stacks *stacks);
void		free_stack(t_list *stack);
int			is_sorted(t_stacks stacks);

#endif