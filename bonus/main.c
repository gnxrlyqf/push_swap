/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:49:35 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 20:49:37 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>


int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((*s1 && (*s1 == *s2)) && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*s1 - *s2);
}

void do_op(char *str, t_stacks *stacks)
{
	if(!ft_strncmp("sa\n", str, 3))
		return (op(stacks, SA, 0));
	if(!ft_strncmp("sb\n", str, 3))
		return (op(stacks, SB, 0));
	if(!ft_strncmp("ss\n", str, 3))
		return (op(stacks, SS, 0));
	if(!ft_strncmp("pa\n", str, 3))
		return (op(stacks, PA, 0));
	if(!ft_strncmp("pb\n", str, 3))
		return (op(stacks, PB, 0));
	if(!ft_strncmp("ra\n", str, 3))
		return (op(stacks, RA, 0));
	if(!ft_strncmp("rb\n", str, 3))
		return (op(stacks, RB, 0));
	if(!ft_strncmp("rr\n", str, 3))
		return (op(stacks, RR, 0));
	if(!ft_strncmp("rra\n", str, 4))
		return (op(stacks, RRA, 0));
	if(!ft_strncmp("rrb\n", str, 4))
		return (op(stacks, RRB, 0));
	if(!ft_strncmp("rrr\n", str, 4))
		return (op(stacks, RRR, 0));
	get_next_line(-1);
	free_stack(stacks->b);
	free_stack(stacks->a);
	write(2, "Error\n", 6);
	free(str);
	exit(1);
}

int	main(int ac, char **av)
{
	char	*buffer;
	t_stacks stacks;

	if (ac <= 2)
		return (0);
	if (!validate_input(av + 1))
		return (write(2, "Error\n", 6));
	stacks = init_stack(av + 1);
	buffer = get_next_line(0);
	while (buffer)
	{
		do_op(buffer, &stacks);
		free(buffer);
		buffer = get_next_line(0);
	}
	is_sorted(stacks);
	free_stack(stacks.a);
	free_stack(stacks.b);
	return (0);
}

// int main(int ac, char **av)
// {
// 	t_stacks	stacks;

// 	if (ac <= 2)
// 		return (0);
// 	if (!validate_input(av + 1))
// 		return (write(2, "Error\n", 6));
// 	stacks = init_stack(av + 1);
// 	if (checker(&stacks))
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);	
// }