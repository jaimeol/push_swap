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
	int		k;

	*stack = NULL;
	i = 1;
	while (argv[i])
	{
		k = 0;
		input = ft_split(argv[i], ' ');
		while (input[k])
			is_valid_number(input[k++]);
		new_stack(input, stack);
		j = 0;
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
	assign_positions(&stack_a);
	if (!stack_a || valid_input(stack_a) == 0 || sorted(stack_a) == 0)
		return (0);
	if (stack_a->size == 2)
		sort2(&stack_a);
	else if (stack_a->size == 3)
		sort3(&stack_a);
	else if (stack_a->size > 3)
		sortelse(&stack_a, &stack_b);
	free_stack(&stack_a);
	exit(0);
}
