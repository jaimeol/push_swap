/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:06:45 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/26 19:06:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(int n, t_list **stack)
{
	t_list	*node;
	t_list	*i;

	node = (t_list *) malloc (sizeof (t_list));
	if (!node)
		return (NULL);
	node->num = n;
	node->next = NULL;
	i = *stack;
	if (*stack)
	{
		while (i->next)
			i = i->next;
		i->next = node;
	}
	else
		*stack = node;
	*stack->cont++;
}

void	free_stack(t_list **stack)
{
	int		i;
	t_list	*next_node;

	i = *stack;
	while (i)
	{
		next_node = i->next;
		free (i);
		i = next_node;
	}
	*stack = NULL;
	return (NULL);
}

void	new_stack(char **input, t_list **stack)
{
	int			i;
	long int	num;

	i = 0;
	while (input[i])
	{
		num = ft_atoi(input[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_stack(stack);
			write(2, "Error\n", 6);
			return ;
		}
		//Función para añadir el stack
		i++;
	}
}
