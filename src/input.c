/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:02:16 by fbraune           #+#    #+#             */
/*   Updated: 2025/05/29 16:19:57 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

static int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*make_input(char **argv, char *input)
{
	int	i;

	i = 1;
	input = NULL;
	while (argv[i])
	{
		input = ft_strjoin(input, argv[i]);
		if (!input)
			return (NULL);
		if (argv[i + 1])
		{
			input = ft_strjoin(input, " ");
			if (!input)
				return (NULL);
		}
		i++;
	}
	return (input);
}

int	parse_input(char *input, t_stack **stack_a)
{
	char		**split;
	int			i;
	long int	num;

	split = ft_split(input, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_valid_num(split[i]))
			return (free_array(split), 0);
		num = ft_atoli(split[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_array(split), 0);
		if (!node_add(stack_a, (int)num))
			return (free_array(split), free_stack(stack_a), 0);
		i++;
	}
	return (free_array(split), 1);
}
