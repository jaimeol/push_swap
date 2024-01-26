/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:34:52 by jolivare          #+#    #+#             */
/*   Updated: 2023/12/19 16:36:23 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	int				cont;
}	t_list;

void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list	**stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ft_putstr(char *s);
t_list		*ft_lstnew(int num);
t_list		*ft_lstlast(t_list *stack);
static void	sort2(t_list **stack);
static void	sort3(t_list **stack);
static void	sort4(t_list **stack_a, t_list **stack_b);
static void	sort5(t_list **stack_a, t_list **stack_b);

#endif