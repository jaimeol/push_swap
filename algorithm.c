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

void	short3(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	if ((*stack) > last)
		sa(stack);
	else if (*stack < last)
		ra(stack);
	else if (*stack -> next > (*stack) &&)
		rra(stack);
}
