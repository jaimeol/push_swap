/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:05:38 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/07 16:03:24 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	sortelse(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
	{
		pb(stack_a, stack_b);
		if ((*stack_a)->size != 3)
			pb(stack_a, stack_b);
	}
	while ((*stack_a)->size != 3)
	{
		get_cost(stack_a);
		get_cost(stack_b);
		ideal_positions(stack_a, *stack_b);
		//Falta la decisión y luego a ver
	}
	check_max_b(stack_b);
	sort3(stack_a);
	return_to_a(stack_a, stack_b);
}

void	return_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		min_a;

	min_a = (*stack_a)->num;
	while (*stack_b)
	{
		last = ft_lstlast(*stack_a);
		if (min_a >= (*stack_a)->num  && min_a > (*stack_a)->num)
			pa(stack_a, stack_b);
		else if (last->num > (*stack_a)->num)
			rra(stack_a);
		else
			pa(stack_a, stack_b);
	}
	while (last->num < (*stack_a)->num)
	{
		rra(stack_a);
		last = ft_lstlast(*stack_a);
	}
}

void	decision(t_list **stack_a, t_list **stack_b)
{
	t_list	*move;

	move = lower_cost(stack_a, stack_b);
	while (move->pos > (*stack)->size / 2
		&& move->true_pos->pos <= (*stack_b)->size / 2
		&& move != (*stack_a)
		&& move->true_pos != (*stack_b)) 
		rrr(stack_a, stack_b);
	while 
}
