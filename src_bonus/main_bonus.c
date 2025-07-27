/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:35:34 by fbraune           #+#    #+#             */
/*   Updated: 2025/07/27 15:24:28 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	execute_operations(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

static int	test_sort(int fd, t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		read;

	line = NULL;
	read = -1;
	while (read != 0)
	{
		read = get_next_line(fd, &line);
		if (read < 0)
		{
			if (line)
				free(line);
			break ;
		}
		if (!line)
			return (0);
		if (!execute_operations(line, stack_a, stack_b))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*input;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	input = make_input(argv);
	if (!input)
		return (1);
	if (!parse_input(input, &a) || check_duplicates(a))
		return (free(input), free_stack(&a), write(2, "Error\n", 6), 1);
	free(input);
	if (!test_sort(0, &a, &b))
		return (free_stack(&a), free_stack(&b), write(2, "Error\n", 6), 1);
	if (b)
		write(1, "KO\n", 3);
	else if (is_sorted(&a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
