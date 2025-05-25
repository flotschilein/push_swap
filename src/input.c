/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:02:16 by fbraune           #+#    #+#             */
/*   Updated: 2025/05/25 16:23:32 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i]0)
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
char    *make_input(char **argv, char *input)
{
    int i;

    i = 1;
    input = NULL;
    while (argv[i])
    {
        input = strjoin(input, argv[i]);
        if (!input)
            return (NULL);
        if (argv[i + 1])
        {
            input = strjoin(input, " ");
            if (!input)
                return (NULL);
        }
        i++;
    }
    return (input);
}

int parse_input(char *input, t_stack **stack_a)
{
	char **split;
	int i;
	long int num;

	split = ft_split(input, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
        if (!is_valid_num)
            return (free_array(split),0);
        num = ft_atoli(split[i]);
        if (num > INT_MAX || num < INT_MIN)
            return (free_array(split),0);
        if(!node_add(stack_a, (int)num))
            return (free_array(split),0);
        i++;
	}
    return (free_array(split),1);
}