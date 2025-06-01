/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:58:36 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/01 18:56:11 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
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
	int	push;

	push = size - 3;
	while (push != 0)
	{
		if ((*stack_a)->index == 0 || ((*stack_a)->index == 1 && size == 5))
		{
			pb(stack_a, stack_b);
			push--;
		}
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	if (size == 5 && (*stack_b)->index == 0 && (*stack_b)->next)
		sb(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}

static void	push_back(t_stack **stack_a, t_stack **stack_b, int c)
{
	int		p;
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
			p = 0;
			cur = *stack_b;
			while (cur && cur->index != c - 1 && ++p)
				cur = cur->next;
			if (p == 1)
				sb(stack_b);
			else if (p <= stack_size(*stack_b) / 2)
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

	size = stack_size(*stack_a);
	current = *stack_a;
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
