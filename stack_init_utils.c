/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:36:12 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/10 22:18:21 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
#include <stdio.h>

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	long			best_match;
	t_stack_node	*current_a;
	t_stack_node	*target_node;

	target_node = NULL;
	while (b)
	{
		best_match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			target_node = return_smallest(a);
		b->target_node = target_node;
		// if (target_node)
		// printf("Target node: %d", b->target_node->value);
		b = b->next;
	}
}

static void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		if (b->above_median)
			b->push_price = b->index;
		else
			b->push_price = len_b - (b->index);
		if (b && b->target_node && b->target_node->above_median)
			b->push_price += b->target_node->index;
		else if (b && b->target_node && !b->target_node->above_median)
			b->push_price += len_a - (b->target_node->index);
		b = b->next;
	}
}

static void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*best_match_node;
	long			best_match_value;

	if (!b)
		return ;
	best_match_value = INT_MAX;
	while (b != NULL)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	calibrate_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
