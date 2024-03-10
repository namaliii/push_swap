/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:01:47 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/10 14:24:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_ordered(t_stack_node *stack)
{
	if (stack == NULL)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*return_biggest(t_stack_node *stack)
{
	int				biggest_value;
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_value = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest_value)
		{
			biggest_node = stack;
			biggest_value = stack->value;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = return_biggest(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		calibrate_nodes(*a, *b);
		push_ready(a, return_smallest(*a), 'a');
		pb(a, b);
	}
}
