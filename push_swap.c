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

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (argc == 2)
		sort2(&stack_a);
	else if (argc == 3)
		sort3(&stack_a);
	else if (argc == 4)
		sort4(&stack_a, &stack_b);
	else if (argc == 5)
		sort5(&stack_a, &stack_b);
}
