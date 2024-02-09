/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:54:59 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/03 19:27:46 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack->num < min->num)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*find_max(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (stack->num > max->num)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
