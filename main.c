/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:19:02 by anamieta          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:31 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack_node **a, t_stack_node **b)
{
	if (!stack_ordered(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			push_swap(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split;

	a = NULL;
	b = NULL;
	split = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		stack_init(&a, split, argc);
	}
	else
		stack_init(&a, argv + 1, argc);
	sort(&a, &b);
	if (split)
		free_array(split);
	free_stack(&a);
	free_stack(&b);
	return (0);
}