/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:58:36 by fbraune           #+#    #+#             */
/*   Updated: 2025/05/29 18:40:05 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
	{
		// TODO: Implement 3 number sort
	}
	else if (size == 4 || size == 5)
	{
		// TODO: Implement 4-5 number sort
	}
}

static void	push_back(t_stack **stack_a, t_stack **stack_b, int count)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == count - 1)
		{
			pa(stack_a, stack_b);
			count--;
		}
		else
			rrb(stack_b);
	}
}

static void	k_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	range;
	int	count;

	count = 0;
	range = ft_sqrt(size) * 1.6;
	while (size != 0)
	{
		if ((*stack_a)->index <= count)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			count++;
            size--;
		}
		else if ((*stack_a)->index < count + range)
		{
			pb(stack_a, stack_b);
			count++;
            size--;
		}
		else
			ra(stack_a);
	}
	push_back(stack_a, stack_b, count);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = *stack_a;
	while (current)
	{
		size++;
		current = current->next;
	}
	if (size <= 5)
	{
		small_sort(stack_a, stack_b, size);
		return ;
	}
	k_sort(stack_a, stack_b, size);
}
