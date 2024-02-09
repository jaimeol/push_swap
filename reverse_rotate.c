/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:30:19 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/04 20:42:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*current;
	int		aux_size;

	aux_size = (*stack)->size;
	last = ft_lstlast(*stack);
	current = *stack;
	while (current->next != last)
		current = current->next;
	current->next = NULL;
	last->next = *stack;
	*stack = last;
	(*stack)->size = aux_size;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}

/*int main()
{
	t_list	*stack_a = NULL;
	t_list	*aux;
	for (int i = 1; i <= 5; ++i) 
	{
		t_list *newNode = (t_list *)malloc(sizeof(t_list));
        newNode->num = i;
        newNode->next = stack_a;
        stack_a = newNode;
    }
	printf("Stack A:\n");
	aux = stack_a;
	while(aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
	rra(&stack_a);
	//rra(&stack_a);

	printf("Stack A después de rotate:\n");
	aux = stack_a;
	while(aux != NULL)
	{
		printf("%d\n", aux -> num);
		aux = aux -> next;
	}
}
*/