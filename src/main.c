/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:18:26 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/01 18:22:06 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*input;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	input = NULL;
	input = make_input(argv, input);
	if (!input)
		return (1);
	if (!parse_input(input, &stack_a) || check_duplicates(stack_a))
		return (free(input), free_stack(&stack_a), write(2, "Error\n", 6), 1);
	assign_indices(&stack_a);
	sort_stack(&stack_a, &stack_b);
	free(input);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
