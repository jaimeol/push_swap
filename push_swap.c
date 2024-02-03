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
	

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit (0);
	get_input(argv, &stack_a);
	if (!stack_a || valid_input(stack_a) == 0 || sorted(stack_a) == 0)
		return (0);

	/*printf("Stack A:\n");
	printf("Num	Pos	Right Pos\n");
	aux2 = stack_a;
	while (aux2 != NULL)
	{
		printf("%d	%d	%d\n", aux2->num, aux2->pos, aux2->right_pos);
		aux2 = aux2->next;
	}
	aux = stack_b;
	printf("Stack B:\n");
	while (aux != NULL)
	{
		printf("%d\n", aux->num);
		aux = aux->next;
	}
	printf("\n");*/
	if (stack_a->size == 2)
		sort2(&stack_a);
	else if (stack_a->size == 3)
		sort3(&stack_a);
	else if (stack_a->size == 4)
		sort4(&stack_a, &stack_b);
	else if (stack_a->size == 5)
		sort5(&stack_a, &stack_b);
	else if (stack_a->size > 5)
		sortelse(&stack_a, &stack_b);
	/*printf("Stack A después del algoritmo:\n");
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
		printf("%d\n", aux->num);
		aux = aux->next;
	}*/

	return (0);
}
