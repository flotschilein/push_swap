/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:58:36 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/03 15:53:27 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_back(t_stack **stack_a, t_stack **stack_b, int c)
{
	int		rotates;
	t_stack	*cur;

	while (*stack_b)
	{
		if ((*stack_b)->index == c - 1)
		{
			pa(stack_a, stack_b);
			c--;
		}
		else
		{
			rotates = 0;
			cur = *stack_b;
			while (cur && cur->index != c - 1 && ++rotates)
				cur = cur->next;
			if (rotates == 1)
				sb(stack_b);
			else if (rotates <= stack_size(*stack_b) / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

static void	k_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	range;
	int	count;

	count = 0;
	range = ft_sqrt(size) * 1.6;
	while (size != count)
	{
		if ((*stack_a)->index <= count)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			count++;
		}
		else if ((*stack_a)->index < count + range)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
	push_back(stack_a, stack_b, count);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = stack_size(*stack_a);
	if (size == 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_four_five(stack_a, stack_b, size);
	else
		k_sort(stack_a, stack_b, size);
}
