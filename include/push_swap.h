/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:27:03 by fbraune           #+#    #+#             */
/*   Updated: 2025/06/03 21:21:43 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					main(int argc, char **argv);

int					check_duplicates(t_stack *stack);
char				*make_input(char **argv);
int					parse_input(char *input, t_stack **stack_a);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

void				sort_stack(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);
void				sort_four_five(t_stack **stack_a, t_stack **stack_b, int size);

int					stack_size(t_stack *stack);
void				free_array(char **array);
int					node_add(t_stack **stack, int value);
void				free_stack(t_stack **stack);
void				assign_indices(t_stack **stack);

char				*get_next_line(int fd);

#endif