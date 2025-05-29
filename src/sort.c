/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:58:36 by fbraune           #+#    #+#             */
/*   Updated: 2025/05/29 17:41:52 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
}
static void	push_back(t_stack stack_a, t_stack stack_b, int count)
{
	if ((stack_b)->index == count - 1)
	{
		pa(stack_a, stack_b);
		count--;
	}
	else
		rrb(stack_b);
}
static void	k_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	range;
	int	count;

	count = 0;
	range = ft_sqrt(size) * 1.5;
	while (stacksize != 0)
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
		stacksize--;
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
