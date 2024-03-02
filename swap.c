/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:41:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/02 12:15:11 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

void	sa(t_stack_node *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node *a, t_stack_node *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
