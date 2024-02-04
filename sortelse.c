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
	int		right_next;
	int		min;
	int		max;
	//t_list	*last;

	size = (*stack_a)->size;
	min = find_min(*stack_a);
	max = find_max(*stack_a);
	//last = ft_lstlast(*stack_a);
	if (size > 3)
	{
		while (size > 3)
		{
			pb(stack_a, stack_b);
			size--;
		}
		sort3(stack_a);
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
}

void	sort_min_extremes(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		min_a;
	int		min_b;

	min_a = find_min(*stack_a);
	min_b = find_min(*stack_b);
	last = ft_lstlast(*stack_b);
	if (min_b < min_a)
	{
		if (min_b == last->num)
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
		}
		else if (min_b == (*stack_b)->num)
			pa(stack_a, stack_b);
	}
}

void	sort_max_extremes(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		max_b;
	int		max_a;

	max_a = find_max(*stack_a);
	max_b = find_max(*stack_b);
	last = ft_lstlast(*stack_b);
	if (max_b > max_a)
	{
		if (max_b == last->num)
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (max_b == (*stack_b)->num)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
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
