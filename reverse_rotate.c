/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:30:19 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/04 20:42:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*first;

	first = *stack;
	*stack = first -> next;
	first -> next = NULL;
	ft_lstaddback((*stack, first));
}

void	rra(t_list **stack_a);
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}
