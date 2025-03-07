/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:12 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:13 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list	*find_node(t_list *stack, int n)
{
	t_list	*curr;

	curr = stack;
	if (!curr)
		return (NULL);
	while (curr)
	{
		if (curr->n == n)
			break ;
		curr = curr->next;
	}
	return (curr);
}

int	stack_size(t_list *stack)
{
	int		size;
	t_list	*curr;

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

int	is_sorted(t_stacks stacks)
{
	t_list	*curr;

	if (stacks.b)
		return (0);
	curr = stacks.a;
	while (1)
	{
		if (curr->n > curr->next->n)
			return (0);
		curr = curr->next;
		if (curr->next == stacks.a)
			break ;
	}
	return (1);
}

void	free_stack(t_list *stack)
{
	t_list	*curr;
	t_list	*temp;
	int		size;

	curr = stack;
	size = stack_size(stack);
	while (size--)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}
