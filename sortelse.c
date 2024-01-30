/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortelse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:12:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/30 18:03:37 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortelse(t_list **stack_a, t_list **stack_b)
{
	t_list	*i;
	int		pos;

	pos = 0;
	i = *stack_a;
	while (i->next)
	{
		i->pos = pos;
		pos++;
		i = i->next;
	}
	find_min(*stack_a);
	find_max(*stack_a);
	find_min(*stack_b);
	find_max(*stack_b);
}