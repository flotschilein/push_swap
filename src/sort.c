/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:58:36 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/06 18:55:29 by fbraune          ###   ########.fr       */
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
			pa(stack_a, stack_b, 1);
			c--;
		}
		else
		{
			rotates = 0;
			cur = *stack_b;
			while (cur && cur->index != c - 1 && ++rotates)
				cur = cur->next;
			if (rotates == 1)
				sb(stack_b, 1);
			else if (rotates <= stack_size(*stack_b) / 2)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
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
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			count++;
		}
		else if ((*stack_a)->index < count + range)
		{
			pb(stack_a, stack_b, 1);
			count++;
		}
		else
			ra(stack_a, 1);
	}
	push_back(stack_a, stack_b, count);
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (1);
		current = current->next;
	}
	return (0);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = stack_size(*stack_a);
	if (!is_sorted(stack_a))
		return ;
	if (size == 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 1);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_four_five(stack_a, stack_b, size);
	else
		k_sort(stack_a, stack_b, size);
}
