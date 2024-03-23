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
				exit_error ();
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

int	is_valid_number(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		exit_error();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit_error();
		i++;
	}
	if (sign && (str[i - 1] == '-' || str[i - 1] == '+'))
		exit_error();
	return (0);
}
