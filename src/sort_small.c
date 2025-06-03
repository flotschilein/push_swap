/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:38:52 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/03 21:50:57 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack_a, 1);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
}

void	sort_four_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	push;

	push = size - 3;
	while (push != 0)
	{
		if ((*stack_a)->index == 0 || ((*stack_a)->index == 1 && size == 5))
		{
			pb(stack_a, stack_b, 1);
			push--;
		}
		else
			ra(stack_a, 1);
	}
	sort_three(stack_a);
	if (size == 5 && (*stack_b)->index == 0 && (*stack_b)->next)
		sb(stack_b, 1);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
