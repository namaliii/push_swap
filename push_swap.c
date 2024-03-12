/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:55:51 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/12 14:42:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ready(t_stack_node **stack, t_stack_node *cheapest,
	char stack_name)
{
	while (cheapest && *stack != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest && cheapest->above_median)
				ra(stack);
			else if (cheapest && !cheapest->above_median)
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest && cheapest->above_median)
				rb(stack);
			else if (cheapest && !cheapest->above_median)
				rrb(stack);
		}
	}
}

static void	transfer_optimal_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while (*a != cheapest->target_node && *b != cheapest)
			rr(a, b);
		current_index(*a);
		current_index(*b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
	{
		while (*a != cheapest->target_node && *b != cheapest)
			rrr(a, b);
		current_index(*a);
		current_index(*b);
	}
	push_ready(b, cheapest, 'b');
	push_ready(a, cheapest->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*smallest;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(a, b);
	sort_three(a);
	while (*b != NULL)
	{
		calibrate_nodes(*a, *b);
		transfer_optimal_node(a, b);
	}
	current_index(*a);
	smallest = return_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
