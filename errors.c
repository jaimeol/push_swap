/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:11:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/23 11:12:04 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(t_list *stack)
{
	t_list	*aux;
	t_list	*start;

	start = stack;
	while (stack->next)
	{
		aux = start;
		while (aux)
		{
			if (stack->num == aux->num && stack != aux)
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			aux = aux->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	sorted(t_list *stack)
{
	t_list	*aux;

	aux = stack;
	while (aux->next)
	{
		if (aux->num > aux->next->num)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	is_letter(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if ((str[i][0] < '0' || str[i][0] > '9') && str[i][0] != '-')
		{
			if (str[i][0] != '+')
			{
				write(2, "Error\n", 6);
				exit (0);
			}
		}
		while(str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
