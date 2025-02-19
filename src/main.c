/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:01 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:03 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stacks	stacks;

	(void)ac;
	if (!validate_input(av + 1))
		return (write(2, "Error\n", 6));
	stacks = init_stack(av + 1);
	if (is_sorted(stacks))
	{
		free_stack(stacks.a);
		return (0);
	}
	else if (stacks.a && stack_size(stacks.a) <= 3)
		sort_three(&stacks);
	else
		sort(&stacks);
	free_stack(stacks.a);
	return (0);
}
