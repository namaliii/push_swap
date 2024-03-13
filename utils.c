/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:37:59 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/13 16:46:52 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*return_smallest(t_stack_node *stack)
{
	long			smallest_value;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	smallest_value = INT_MAX;
	smallest_node = stack;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_node = stack;
			smallest_value = stack->value;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack_node	*return_last_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] && array[i][0] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
