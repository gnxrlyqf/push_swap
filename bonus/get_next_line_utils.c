/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:18:46 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/23 03:45:37 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

t_line	*gnl_add_node(t_line **head, char c)
{
	t_line	*curr;
	t_line	*new;

	new = malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->c = c;
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

void	free_list(t_line **head)
{
	t_line	*current;
	t_line	*temp;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}

char	*make_str(t_line **head, int size)
{
	char	*new;
	t_line	*curr;
	t_line	*temp;
	int		i;

	new = malloc(sizeof(char) * (size + 1));
	if (!new || !*head || !size)
		return (free(new), NULL);
	new[size] = 0;
	i = size;
	curr = *head;
	while (curr && i)
	{
		*(new++) = curr->c;
		i--;
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*head = curr;
	return (new - size);
}

int	listchr_len(t_line *head)
{
	int		len;
	t_line	*curr;

	curr = head;
	len = 0;
	while (curr && curr->c != '\n')
	{
		len++;
		curr = curr->next;
	}
	if (curr)
		len++;
	return (len);
}