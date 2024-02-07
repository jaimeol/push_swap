/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:01:06 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/06 19:01:06 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_list **stack)
{
	int		position;
	t_list	*current;

	position = 0;
	current = *stack;
	while (current != NULL)
	{
		current->pos = position;
		position++;
		current = current->next;
	}
}

void	ideal_positions(t_list **stack_a, t_list *stack_b)
{
	t_list	*aux;
	t_list	*aux2;
	int		max;

	aux = *stack_a;
	while (aux)
	{
		aux2 = stack_b;
		max = INT_MIN;
		while (aux2)
		{
			if (max < aux2->num && aux2->num < aux->num)
			{
				aux->right_pos = aux2;
				max = aux2->num;
			}
		}
		if (max == INT_MIN)
			aux->right_pos->num = find_max(stack_b);
		aux = aux->next;
	}
}
