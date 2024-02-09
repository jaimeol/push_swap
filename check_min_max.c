/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:16:03 by jolivare          #+#    #+#             */
/*   Updated: 2024/02/08 12:16:32 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_max_b(t_list **stack_b)
{
	t_list	*max;

	max = find_max(*stack_b);
	if ((*stack_b) == max)
		return ;
	while ((*stack_b) != max)
	{
		if (max->num <= (*stack_b)->size / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	chec