#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign *= (44 - *str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

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
int main(int ac, char **av)
{
	t_stacks stacks;

	if (ac < 3)
		return (1);
	stacks = init_stack(ac, av);
	print_stack(stacks.a);
	op(&stacks, RA);
	print_stack(stacks.a);
}