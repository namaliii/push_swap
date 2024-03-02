/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:51:03 by anamieta          #+#    #+#             */
/*   Updated: 2024/02/24 17:00:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_duplicated(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	error_nondigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i])
	{
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

static void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	handle_errors(t_stack_node **a, char *argv, long n)
{
	if (error_nondigit(argv))
		free_errors(a);
	if (n > INT_MAX || n < INT_MIN)
		free_errors(a);
	if (error_duplicated(*a, n))
		free_errors(a);
}
