/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:11:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/23 11:12:04 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(t_list *stack)
{
	t_list	*aux;
	t_list	*start;

	start = stack;
	while (stack->next)
	{
		aux = start;
		while (aux)
		{
			if (stack->num == aux->num && stack != aux)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			aux = aux->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	sorted(t_list *stack)
{
	int	flag;

	flag = 0;
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			flag = 1;
		stack = stack->next;
	}
	return (flag);
}
