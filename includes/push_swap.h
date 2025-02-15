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
	RRR
} t_op;

typedef struct s_move {
	t_op op;
	struct s_move *next;
} t_move;

void swap(t_list **stack);
void push(t_list **s1, t_list **s2);
void rotate(t_list **stack, int rev);
void op(t_stacks *s, t_op op, t_move **moves);
t_stacks init_stack(int ac, char **av);
t_list	*add_node(t_list **head, int n);
void print_stack(t_list *stack);
int stack_size(t_list *stack);
int	ft_atoi(const char *str);
t_list *get_node(t_list *stack, int index);
int calc_cost_b(int n, t_list *b, int size, t_list **best);
t_stacks find_best(t_stacks *stacks, int size_a, int size_b);
int get_node_index(t_list *stack, t_list *node);
int min(int a, int b);
int min_abs(int a, int b);
void sort(t_stacks *stacks);
void moves(t_stacks *stacks, int pos_a, int pos_b, t_move **moves);
t_move	*add_move(t_move **head, t_op op);
void optimize(t_move *moves);
t_list *get_max(t_list *stack);
t_list *get_min(t_list *stack);
t_list *get_next(t_list *stack, int n);
void loop_op(t_stacks *s, t_op opcode, int count, t_move **moves);

#endif