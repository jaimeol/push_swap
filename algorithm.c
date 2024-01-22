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

static void	sort3(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	if ((*stack)-> num < last-> num && (*stack)-> num < (*stack)-> next-> num)
	{
		if (last-> num > (*stack)-> num)
			ra(stack);
	}
	else if ((*stack)-> num > last-> num)
	{
		if ((*stack)-> num < (*stack)-> next-> num)
			sa(stack);
	}
}

static void	sort5(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)-> next-> num < (*stack_a)-> num)
	{
		printf("Hola\n");
		pb(stack_a, stack_b);
	}
}

int	main()
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list	*aux;
	
	t_list	*node1, *node2, *node3, *node4, *node5;

	node1 = malloc(sizeof(t_list));
	node1 -> num = 4;
	node1 -> next = NULL;

	node2 = malloc(sizeof(t_list));
	node2 -> num = 1;
	node2 -> next = NULL;

	node3 = malloc(sizeof(t_list));
	node3 -> num = 5;
	node3 -> next = NULL;

	node4 = malloc(sizeof(t_list));
	node4 -> num = 2;
	node4 -> next = NULL;

	node5 = malloc(sizeof(t_list));
	node5 -> num = 3;
	node5 -> next = NULL;

	stack_a = node1;
	node1-> next = node2;
	node2-> next = node3;
	node3-> next = node4;
	node4-> next = node5;

	printf("Stack A:\n");
	aux = stack_a;
	while (aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	aux = stack_b;
	printf("Stack B:\n");
	while (aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	sort5(&stack_a, &stack_b);
	printf("Stack A después de sort5:\n");
	aux = stack_a;
	while (aux != NULL)
	{
		printf("%d\n", aux->num);
		aux = aux->next;
	}
	printf("Stack B después de sort5:\n");
	aux = stack_b;
	while (aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	return 0;
}
