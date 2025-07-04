/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:15:19 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/03 22:18:54 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_one(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stack **stack_a, int c)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate_one(stack_a);
	if (c == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int c)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate_one(stack_b);
	if (c == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int c)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next) && (!stack_b || !*stack_b
			|| !(*stack_b)->next))
		return ;
	rotate_one(stack_a);
	rotate_one(stack_b);
	if (c == 1)
		write(1, "rr\n", 3);
}
