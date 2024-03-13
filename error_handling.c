/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:51:03 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/13 16:59:54 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_duplicated(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	error_nondigit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-')
		&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = NULL;
	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a, char **argv, int argc)
{
	free_stack(a);
	if (argc == 2)
		free_array(argv);
	write(2, "Error\n", 6);
	exit(1);
}

bool	handle_errors(t_stack_node **a, char *argv, long n)
{
	if (error_nondigit(argv))
		return (false);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	if (error_duplicated(*a, n))
		return (false);
	return (true);
}
