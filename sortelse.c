/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortelse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:12:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/01 14:26:44 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortelse(t_list **stack_a, t_list **stack_b)
{
	int		size;

	size = (*stack_a)->size;
	//min = find_min(*stack_a);
	//max = find_max(*stack_a);
	if (size > 3)
	{
		while (size > 3)
		{
			pb(stack_a, stack_b);
			size--;
		}
		sort3(stack_a);
		sort_min_extremes(stack_a, stack_b);
		sort_max_extremes(stack_a, stack_b);
		ft_find_place_a(*stack_a, (*stack_b)->num);
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
