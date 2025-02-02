#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list {
	int n;
	struct s_list *prev;
	struct s_list *next;
} t_list;

typedef struct s_stacks {
	t_list *a;
	t_list *b;
} t_stacks;

typedef enum op {
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
	RRR
} t_op;

void swap(t_list **stack);
void push(t_list **s1, t_list **s2);
void rotate(t_list **stack, int rev);
void op(t_stacks *s, t_op op);

#endif