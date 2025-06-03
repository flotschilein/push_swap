/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:35:34 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/03 21:21:19 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void get_line(int fd)
{
    char *line;
    int read;

    line = NULL;
    wh
}

int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char *input;
    char *line;

    if (argc == 1)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    input = make_input(argv);
    if (!input)
        return (1);
    if (!parse_input(input, &stack_a) || check_duplicates(stack_a))
        return (free(input), free_stack(&stack_a), write(2, "Error\n", 6), 1);
    line = get_line(0);
}
