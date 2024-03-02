/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:02:25 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/02 12:12:18 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*pre_last;
	t_stack_node	*last;

	if (!*head || !(*head)->next)
		return ;
	pre_last = NULL;
	last = *head;
	while (last->next)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	last->prev = NULL;
	last->next = *head;
	*head = last;
	(*head)->next->prev = *head;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
