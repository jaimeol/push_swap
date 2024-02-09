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

int	rrr_cost(t_list *stack_a, t_list *stack_b, int cont)
{
	int	sol;

	sol = stack_a->cost + stack_a->right_pos->cost;
	if (stack_a->pos <= cont && stack_a->right_pos->pos <= (stack_b->size / 2))
	{
		if (stack_a->cost <= stack_a->right_pos->cost)
			sol = stack_a->right_pos->cost;
		else
			sol = stack_a->cost;
	}
	return (sol);
}

t_list	*lower_cost(t_list *stack_a, t_list *stack_b)
{
	t_list	*i;
	int		total_cost;
	int		cont;
	int		aux;

	cont = stack_a->size / 2;
	total_cost =  stack_a->cost + stack_a->right_pos->cost;
	i = stack_a;
	while (stack_a)
	{
		aux = rrr_cost(stack_a, stack_b, cont);
		if (aux < total_cost)
		{
			total_cost = aux;
			i = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (i);
}
