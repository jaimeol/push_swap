/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:19:23 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/03 19:49:12 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_list **stack)
{
	int		position;
	t_list	*current;

	position = 1;
	current = *stack;
	while (current != NULL)
	{
		current->pos = position;
		position++;
		current = current->next;
	}
}

