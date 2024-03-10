/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:55:51 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/10 22:18:02 by anamieta         ###   ########.fr       */
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
	if (cheapest->target_node && cheapest->target_node->above_median)
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

// #include <stdio.h>

// void	print_stacks(t_stack_node *a, t_stack_node *b)
// {
// 	printf("Stack a:\n");
// 	while (a)
// 	{
// 		printf("value: %d, index: %d, push price: %d, above median: %d, cheapest: %d\n",
// 			a->value, a->index, a->push_price, a->above_median, a->cheapest);
// 		a = a->next;
// 	}
// 	printf("Stack b:\n");
// 	while (b)
// 	{
// 		if (b->target_node)
// 			printf("value: %d, index: %d, push price: %d, above median: %d, cheapest: %d, target node value: %d\n",
// 				b->value, b->index, b->push_price, b->above_median, b->cheapest, b->target_node->value);
// 		else
// 		{
// 			printf("BOBERK KURWA! ");
// 						printf("value: %d, index: %d, push price: %d, above median: %d, cheapest: %d\n",
// 				b->value, b->index, b->push_price, b->above_median, b->cheapest);
// 		}
// 		b = b->next;
// 	}
// 	printf("Finito.\n");
// }

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*smallest;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		calibrate_nodes(*a, *b);
		transfer_optimal_node(a, b);
		// print_stacks(*a, *b);
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
