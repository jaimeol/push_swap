/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:30:26 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/04 20:19:01 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	last -> next = (*stack);
	*stack = (*stack)-> next;
	last -> next -> next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}

int main()
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list	*aux;
	for (int i = 1; i <= 5; ++i) 
	{
		t_list *newNode = (t_list *)malloc(sizeof(t_list));
        newNode->num = i;
        newNode->next = stack_a;
        stack_a = newNode;
    }
	for (int i = 1; i <= 5; ++i) 
	{
		t_list *newNode = (t_list *)malloc(sizeof(t_list));
        newNode->num = i;
        newNode->next = stack_b;
        stack_b = newNode;
    }
	printf("Stack A:\n");
	aux = stack_a;
	while(aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	printf("Stack B:\n");
	aux = stack_b;
	while(aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	rr(&stack_a, &stack_b);

	printf("Stack A después de rotate:\n");
	aux = stack_a;
	while(aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}


	printf("Stack B después de rotate:\n");
	aux = stack_a;
	while(aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
}
