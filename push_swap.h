/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:29:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/06 20:20:00 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//utils, errors and inits
char			**ft_split(char const *s, char c);
void			handle_errors(t_stack_node **a, char *argv, long n);
void			stack_init(t_stack_node **a, char **argv);
void			free_stack(t_stack_node **stack);
void			push_ready(t_stack_node **stack, t_stack_node *cheapest,
					char stack_name);

//nodes
void			calibrate_nodes(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*return_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
t_stack_node	*return_last_node(t_stack_node *stack);

//operations
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
//sorting algorythms
bool			stack_ordered(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);

#endif