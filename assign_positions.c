/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:19:23 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/31 14:58:11 by jolivare         ###   ########.fr       */
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


void	ideal_positions(t_list **stack_a)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = *stack_a;
	while (current_a != NULL)
	{
		current_a->right_pos = 1;
		current_b = *stack_a;
		while (current_b != NULL)
		{
			if (current_b != current_a && current_b->num < current_a->num)
			{
				current_a->right_pos++;
			}
			current_b = current_b->next;
		}
		current_a = current_a->next;
	}
}

