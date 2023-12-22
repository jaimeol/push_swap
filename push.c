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
#include <stdlib.h>
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

static void	push(t_list **src, t_list **dest)
{
	t_list	*aux;

	if (*dest == NULL)
		return ;
	aux = (*src)-> next;
	(*src)->next = *dest;
	*src = *dest;
	*src = aux;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_b);
	ft_putstr("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

/*void printList(t_list *head) {
    while (head != NULL) {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}

int main() {
    t_list *stack1 = NULL;
    t_list *stack2 = NULL;

    // Agregar algunos elementos a stack1
    for (int i = 5; i >= 1; i--) {
        t_list *newNode = (t_list *)malloc(sizeof(t_list));
        newNode->num = i;
        newNode->next = stack1;
        stack1 = newNode;
    }

    // Imprimir el estado inicial de las pilas
    printf("Stack 1: ");
    printList(stack1);
    printf("Stack 2: ");
    printList(stack2);

    // Llamar a la función push para pasar el primer elemento de stack1 a stack2
    pa(&stack1, &stack2);

    // Imprimir el estado final de las pilas
    printf("Después de push:\n");
    printf("Stack 1: ");
    printList(stack1);
    printf("Stack 2: ");
    printList(stack2);

    return 0;
}*/