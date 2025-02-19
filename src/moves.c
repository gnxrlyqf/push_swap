/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:04 by mchetoui          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:05 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	moves(t_stacks *stacks, int pos_a, int pos_b)
{
	int	size_a;
	int	size_b;
	int	a;
	int	b;

	size_a = stack_size(stacks->a);
	size_b = stack_size(stacks->b);
	a = pos_a - size_a * (pos_a > size_a / 2);
	b = pos_b - size_b * (pos_b > size_b / 2);
	if (a * b > 0)
	{
		loop_op(stacks, RR + 3 * (a < 0), min(abs(a), abs(b)));
		loop_op(stacks, RA + (abs(b) > abs(a)) + 3 * (a < 0), abs(a - b));
	}
	else
	{
		loop_op(stacks, RA + 3 * (a < 0), abs(a));
		loop_op(stacks, RB + 3 * (b < 0), abs(b));
	}
	op(stacks, PB, 1);
}

void	loop_op(t_stacks *s, t_op opcode, int count)
{
	while (count--)
		op(s, opcode, 1);
}
