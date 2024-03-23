/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:38:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/07 17:38:11 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	sort3(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	if ((*stack)->num > last->num)
	{
		if ((*stack)->num > (*stack)->next->num
			&& last->num < (*stack)->next->num)
		{
			sa(stack);
			rra(stack);
		}
		else if ((*stack)->num < (*stack)->next->num)
			rra(stack);
		else if ((*stack)->num > last->num
			&& (*stack)->num > (*stack)->next->num)
			ra(stack);
	}
	else if ((*stack)->num < last->num && last->num < (*stack)->next->num)
	{
		rra(stack);
		sa(stack);
	}
	else if ((*stack)->num > (*stack)->next->num && last->num > (*stack)->num)
		sa(stack);
}
