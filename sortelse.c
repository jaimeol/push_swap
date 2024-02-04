/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortelse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:12:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/03 20:09:06 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortelse(t_list **stack_a, t_list **stack_b)
{
	int		size;

	size = (*stack_a)->size;
	if (size > 3)
	{
		while (size > 3)
		{
			pb(stack_a, stack_b);
			size--;
		}
		sort3(stack_a);
		rotate_push(stack_a, stack_b);
	}
}

int	find_right_next(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		diff;
	int		sol;
	t_list	*aux;

	aux = *stack_a;
	i = INT_MAX;
	while (aux)
	{
		diff = aux->num - (*stack_b)->num;
		if (aux->num > (*stack_b)->num && diff < i)
		{
			sol = aux->num;
			i = diff;
		}
		aux = aux->next;
	}
	if (i == INT_MAX)
		return (find_min(*stack_a));
	return (sol);
}

void	rotate_push(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;
	int	right_next;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	while ((*stack_b))
	{
		right_next = find_right_next(stack_a, stack_b);
		if ((*stack_b)->num != min || (*stack_b)->num != max)
		{
			while ((*stack_a)->num != right_next)
				ra(stack_a);
			pa(stack_a, stack_b);
		}
	}
	while ((*stack_a)->num != min)
		ra (stack_a);
}
