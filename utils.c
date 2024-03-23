/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:19:17 by jolivare          #+#    #+#             */
/*   Updated: 2023/12/19 11:19:53 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*k;

	k = malloc(sizeof(t_list));
	if (k == NULL)
		return (NULL);
	k -> num = num;
	k -> next = NULL;
	return (k);
}

t_list	*ft_lstlast(t_list *stack)
{
	while (stack && stack -> next)
		stack = stack -> next;
	return (stack);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	res;
	size_t	i;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = (res + str[i] - '0') * 10;
		i++;
	}
	res = (res / 10) * sign;
	return (res);
}

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

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
