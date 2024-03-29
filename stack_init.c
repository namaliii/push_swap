/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:22:03 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/13 19:13:55 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	result;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static void	append_node(t_stack_node **stack, long n)
{
	t_stack_node	*new;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (new == NULL)
		return ;
	*new = (t_stack_node){n, -1, -1, false, false, NULL, NULL, NULL};
	if (*stack)
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	else
	{
		new->prev = NULL;
		*stack = new;
	}
}

void	stack_init(t_stack_node **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (!handle_errors(a, argv[i], n))
			free_errors(a, argv, argc);
		append_node(a, (int)n);
		i++;
	}
}
