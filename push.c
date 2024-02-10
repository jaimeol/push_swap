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
	t_list	*aux;
	t_list	*newnode;

	newnode = ft_lstnew((*src)->num);
	newnode -> next = *dest;
	*dest = newnode;
	aux = *src;
	*src = (*src)-> next;
	free(aux);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	if (!(*stack_a))
		size_a = 0;
	else
		size_a = (*stack_a)->size;
	size_b = (*stack_b)->size;
	if (!*stack_a)
		return ;
	push(stack_b, stack_a);
	write (1, "pa\n", 3);
	(*stack_a)->size = size_a + 1;
	if (*stack_b)
		(*stack_b)->size = size_b - 1;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	if (!*stack_b)
		size_b = 0;
	else
		size_b = (*stack_b)->size;
	size_a = (*stack_a)->size;
	if (!*stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	(*stack_a)->size = size_a - 1;
	(*stack_b)->size = size_b + 1;
}

/*int	main()
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list	*aux;

	t_list	*node1, *node2, *node3, *node4, *node5;

	node1 = malloc(sizeof(t_list));
	node1 -> num = 1;
	node1 -> next = NULL;

	node2 = malloc(sizeof(t_list));
	node2 -> num = 2;
	node2 -> next = NULL;

	node3 = malloc(sizeof(t_list));
	node3 -> num = 3;
	node3 -> next = NULL;

	node4 = malloc(sizeof(t_list));
	node4 -> num = 4;
	node4 -> next = NULL;

	node5 = malloc(sizeof(t_list));
	node5 -> num = 5;
	node5 -> next = NULL;

	stack_a = node1;
	node1-> next = node2;
	node2-> next = node3;

	stack_b = node4;
	node4 -> next = node5;
	printf("Stack A:\n");
	aux = stack_a;
	while (aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	printf("Stack B:\n");
	aux = stack_b;
	while (aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	pb(&stack_a, &stack_b);

	printf("Stack A después de push:\n");
	aux = stack_a;
	while (aux != NULL)
	{
    	printf("%d\n", aux->num);
    	aux = aux->next;
	}

	printf("Stack B después de push:\n");
	aux = stack_b;
	while (aux != NULL)
	{
    	printf("%d\n", aux->num);
    	aux = aux->next;
	}
	return 0;
}
*/