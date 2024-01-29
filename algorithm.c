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

void	sort2(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	sort3(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	if ((*stack)->num > last->num)
	{
		if ((*stack)->num > (*stack)->next->num
			&& last->num < (*stack)->next->num)
		{
			sa(stack);
			rra(stack);
		}
		else if ((*stack)->num < (*stack)->next->num)
			rra(stack);
		else if ((*stack)->num > last->num
			&& (*stack)->num > (*stack)->next->num)
			ra(stack);
	}
	else if ((*stack)->num < last->num && last->num < (*stack)->next->num)
	{
		rra(stack);
		sa(stack);
	}
	else if (last->num > (*stack)->num && last->num > (*stack)->next->num)
		sa(stack);
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	pb(stack_a, stack_b);
	sort3(stack_a);
	last = ft_lstlast(*stack_a);
	if ((*stack_b)->num < (*stack_a)->num)
		pa(stack_a, stack_b);
	else if (last->num < (*stack_b)->num)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if ((*stack_b)->num < (*stack_a)->next->num)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if ((*stack_b)->num > (*stack_a)->next->num)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort5aux(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if ((*stack_a)->next->next->num > (*stack_b)->num
		&& (*stack_b)->num > (*stack_a)->next->num)
	{
		ra(stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next->next->num < (*stack_b)->num
		&& (*stack_b)->num < last->num)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}

}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	pb(stack_a, stack_b);
	sort4(stack_a, stack_b);
	last = ft_lstlast(*stack_a);
	if ((*stack_a)->num < (*stack_b)->num)
	{
		if (last->num < (*stack_b)->num)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if ((*stack_a)->num < (*stack_b)->num
			&& (*stack_b)->num < (*stack_a)->next->num)
		{
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
			sort5aux(stack_a, stack_b);
	}
	else if ((*stack_a)->num > (*stack_b)->num)
		pa(stack_a, stack_b);
}

/*int	main()
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list	*aux;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*node5;

	node1 = malloc(sizeof(t_list));
	node1 -> num = 2;
	node1 -> next = NULL;

	node2 = malloc(sizeof(t_list));
	node2 -> num = 5;
	node2 -> next = NULL;

	node3 = malloc(sizeof(t_list));
	node3 -> num = 4;
	node3 -> next = NULL;

	node4 = malloc(sizeof(t_list));
	node4 -> num = 2;
	node4 -> next = NULL;

	node5 = malloc(sizeof(t_list));
	node5 -> num = 1;
	node5 -> next = NULL;

	stack_a = node1;
	node1->next = node2;
	node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
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
	printf("\n");
	sort3(&stack_a);
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
	return (0);
}*/
