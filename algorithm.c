/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:05:38 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/09 14:11:01 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortelse(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
	{
		pb(stack_a, stack_b);
		if ((*stack_a)->size != 3)
			pb(stack_a, stack_b);
	}
	while ((*stack_a)->size > 3)
	{
		get_cost(stack_a);
		get_cost(stack_b);
		ideal_positions(stack_a, stack_b);
		decision(stack_a, stack_b);
	}
	check_max_b(stack_b);
	sort3(stack_a);
	return_to_a(stack_a, stack_b);
}

void	return_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		min_a;
	t_list	*max_a;

	min_a = (*stack_a)->num;
	while (*stack_b)
	{
		last = ft_lstlast(*stack_a);
		if (min_a >= (*stack_a)->num && min_a > (*stack_b)->num)
			pa(stack_a, stack_b);
		else if (last->num > (*stack_b)->num)
			rra(stack_a);
		else
			pa(stack_a, stack_b);
	}
	max_a = find_max(*stack_a);
	while (last != max_a)
	{
		if (max_a->pos > ((*stack_a)->size / 2))
		{
			rra(stack_a);
			last = ft_lstlast(*stack_a);
		}
		else if (max_a->pos <= ((*stack_a)->size / 2))
		{
			ra(stack_a);
			last = ft_lstlast(*stack_a);
		}
	}
}

void	decision(t_list **stack_a, t_list **stack_b)
{
	t_list	*move;

	move = lower_cost(*stack_a, *stack_b);
	while (move->pos > (*stack_a)->size / 2
		&& move->right_pos->pos > (*stack_b)->size / 2
		&& move != (*stack_a) && move != (*stack_b))
	{
		rrr(stack_a, stack_b);
		get_cost(stack_a);
		get_cost(stack_b);
		ideal_positions(stack_a, stack_b);
	}
	while (move->pos <= (*stack_a)->size / 2
		&& move->right_pos->pos <= (*stack_b)->size / 2
		&& move != (*stack_a) && move->right_pos != (*stack_b))
	{
		rr(stack_a, stack_b);
		get_cost(stack_a);
		get_cost(stack_b);
		ideal_positions(stack_a, stack_b);
	}
	finish_rotation(move, stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	finish_rotation(t_list *move, t_list **stack_a, t_list **stack_b)
{
	while (move != (*stack_a) && move->pos <= (*stack_a)->size / 2)
		ra(stack_a);
	while (move != (*stack_a) && move->pos > (*stack_a)->size / 2)
		rra(stack_a);
	while (move->right_pos != (*stack_b) 
		&& move->right_pos->pos <= (*stack_b)->size / 2)
		rb(stack_b);
	while (move->right_pos != (*stack_b)
		&& move->right_pos->pos > (*stack_b)->size / 2)
		rrb(stack_b);
}
