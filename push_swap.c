/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:56:24 by jolivare          #+#    #+#             */
/*   Updated: 2023/12/19 12:56:25 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_input(char *argv[], t_list **stack)
{
	int		i;
	int		j;
	char	**input;

	*stack = NULL;
	i = 1;
	while (argv[i])
	{
		input = ft_split(argv[i], ' ');
		if (!input)
			return ;
		else if (input[0] == NULL)
			return ;
		j = 0;
		new_stack(input, stack);
		while (input[j])
		{
			free(input[j]);
			j++;
		}
		free (input);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*aux;

	stack_a = NULL;
	stack_b = NULL;

	get_input(argv, &stack_a);
	if (stack_a->cont == 2)
		sort2(&stack_a);
	else if (stack_a->cont == 3)
		sort3(&stack_a);
	else if (stack_a->cont == 4)
		sort4(&stack_a, &stack_b);
	else if (stack_a->cont == 5)
	{
		printf("Hola\n");
		sort5(&stack_a, &stack_b);
	}
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
	sort5(&stack_a, &stack_b);
	printf("Stack A después de sort:\n");
	aux = stack_a;
	while (aux != NULL)
	{
		printf("%d\n", aux->num);
		aux = aux->next;
	}
}
