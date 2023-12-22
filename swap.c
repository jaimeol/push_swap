/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:54:46 by jolivare          #+#    #+#             */
/*   Updated: 2023/12/19 11:11:12 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

static void	swap(t_list **stack)
{
	t_list	*aux;

	if (!*stack || (*stack)->next == NULL)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}

void printStack(t_list *stack) {
    while (stack) {
        printf("%d ", stack->num);
        stack = stack->next;
    }
    printf("\n");
}

int main() {
    t_list *stack = NULL;
    for (int i = 1; i <= 5; ++i) {
        t_list *newNode = (t_list *)malloc(sizeof(t_list));
        newNode->num = i;
        newNode->next = stack;
        stack = newNode;
    }

    printf("Stack antes de swap: ");
    printStack(stack);

    swap(&stack);

    printf("Stack después de swap: ");
    printStack(stack);

    return 0;
}