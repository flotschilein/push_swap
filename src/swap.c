/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:01:30 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/03 21:47:54 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_two(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a, int c)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap_two(stack_a);
	if (c == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int c)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap_two(stack_b);
	if (c == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int c)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) && (!stack_b || !*stack_b
			|| !(*stack_b)->next))
		return ;
	swap_two(stack_a);
	swap_two(stack_b);
	if (c == 1)
		write(1, "ss\n", 3);
}
