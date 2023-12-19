/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:33:00 by jolivare          #+#    #+#             */
/*   Updated: 2023/12/19 16:29:34 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	aux;

	if (*dest == NULL)
		return ;
	aux = (*src)-> next;
	(*src)->next = *dest;
	*src = *dest;
	*src = aux;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_b)
	ft_putstr("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
