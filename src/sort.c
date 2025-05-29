/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:58:36 by fbraune           #+#    #+#             */
/*   Updated: 2025/05/29 22:05:52 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

static void	sort_four_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		min_index;
	t_stack	*current;
	int		numbers_to_push;

	numbers_to_push = size - 3;  // Push 1 for 4 numbers, 2 for 5 numbers
	while (numbers_to_push--)
	{
		min_index = 0;
		current = *stack_a;
		while (current)
		{
			if (current->value < (*stack_a)->value)
				min_index++;
			current = current->next;
		}
		while (min_index--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
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
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_four_five(stack_a, stack_b, size);
	else
		k_sort(stack_a, stack_b, size);
}
