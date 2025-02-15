#include <push_swap.h>

t_list	*add_node(t_list **head, int n)
{
	t_list	*curr;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
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

t_list *get_node(t_list *stack, int index)
{
	t_list *curr;

	curr = stack;
	while (1)
	{
		if (!index)
			break ;
		curr = curr->next;
		index--;
	}
	return (curr);
}

t_list *get_max(t_list *stack)
{
	t_list *out;
	t_list *curr;
	int max;

	curr = stack;
	out = curr;
	max = 0;
	while (1)
	{
		if (curr->n > max)
		{
			out = curr;
			max = curr->n;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (out);
}
t_list *get_min(t_list *stack)
{
	t_list *out;
	t_list *curr;
	int min;

	curr = stack;
	out = curr;
	min = stack->n;
	while (1)
	{
		if (curr->n < min)
		{
			out = curr;
			min = curr->n;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (out);
}

t_list	*get_next(t_list *stack, int n)
{
	int min;
	t_list *next;
	t_list *curr;

	min = get_max(stack)->n;
	if (n > min)
		return (get_min(stack));
	curr = stack;
	while (1)
	{
		if (curr->n > n && curr->n - n < min)
		{
			next = curr;
			min = curr->n - n;
		}
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (next);
}

int get_node_index(t_list *stack, t_list *node)
{
	t_list *curr;
	int index;

	curr = stack;
	index = 0;
	while (1)
	{
		if (curr == node)
			break ;
		curr = curr->next;
		index++;
		if (curr == stack)
			break ;
	}
	return (index);
}

t_stacks init_stack(int ac, char **av)
{
	t_stacks stacks;
	t_list *stack;
	t_list *prev;
	t_list *new;
	int i;

	i = 1;
	stack = NULL;
	prev = NULL;
	while (i < ac)
	{
		new = add_node(&stack, ft_atoi(av[i++]));
		new->prev = prev;
		prev = new;
	}
	new->next = stack;
	stack->prev = new;
	stacks.a = stack;
	stacks.b = NULL;
	return (stacks);
}

int stack_size(t_list *stack)
{
	int size;
	t_list *curr;
	
	size = 0;
	curr = stack;
	if (!stack)
		return (0);
	while (1)
	{
		curr = curr->next;
		size++;
		if (curr == stack)
			break ;
	}
	return (size);
}

void print_stack(t_list *stack)
{
	t_list *curr;

	curr = stack;
	while (curr)
	{
		printf("%d ", curr->n);
		if (curr->next == stack)
			break ;
		curr = curr->next;
	}
	puts("");
}
