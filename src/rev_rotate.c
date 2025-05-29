/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:14:27 by fbraune           #+#    #+#             */
/*   Updated: 2025/05/28 22:14:49 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate_one(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	rev_rotate_one(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate_one(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) && (!stack_b || !*stack_b
			|| !(*stack_b)->next))
		return ;
	rev_rotate_one(stack_a);
	rev_rotate_one(stack_b);
	write(1, "rrr\n", 4);
}
