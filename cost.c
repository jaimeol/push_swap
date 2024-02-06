/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:20:13 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/03 12:03:19 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_list	**stack)
{
	t_list	*i;
	int		pos;

	pos = 0;
	i = *stack;
	while (i)
	{
		i->pos = pos;
		if (pos > ((*stack)->size / 2))
			i->cost = (*stack)->size - pos;
		else
			i->cost = pos;
		pos++;
		i = i->next;
	}
}
