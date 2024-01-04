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

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new -> next = *stack;
	*stack = new;
}

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