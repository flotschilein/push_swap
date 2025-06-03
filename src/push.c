/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:12:22 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/03 21:45:18 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_one(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dest;
	if (*dest)
		(*dest)->prev = temp;
	temp->prev = NULL;
	*dest = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int c)
{
	push_one(stack_a, stack_b);
	if (c == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int c)
{
	push_one(stack_b, stack_a);
	if (c == 1)
		write(1, "pb\n", 3);
}
