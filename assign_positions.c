/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:19:23 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/01 09:58:06 by jolivare         ###   ########.fr       */
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
	t_list	*current_1;
	t_list	*current_2;

	current_1 = *stack_a;
	while (current_1 != NULL)
	{
		current_1->right_pos = 1;
		current_2 = *stack_a;
		while (current_2 != NULL)
		{
			if (current_2 != current_1 && current_2->num < current_1->num)
			{
				current_1->right_pos++;
			}
			current_2 = current_2->next;
		}
		current_1 = current_1->next;
	}
}
