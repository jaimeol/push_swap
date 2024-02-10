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
	struct s_list	*next;
	struct s_list	*right_pos;
	int				num;
	int				size;
	int				pos;
	int				cost;
}	t_list;

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list	**stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ft_putstr(char *s);
void	add_stack(int n, t_list **stack);
void	free_stack(t_list **stack);
void	new_stack(char **input, t_list **stack);
void	sort2(t_list **stack);
void	sort3(t_list **stack);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort5(t_list **stack_a, t_list **stack_b);
void	check_max_b(t_list **stack_b);
t_list	*ft_lstnew(int num);
t_list	*ft_lstlast(t_list *stack);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);
int		valid_input(t_list *stack);
int		sorted(t_list *stack);
void	assign_positions(t_list **stack);
void	ideal_positions(t_list **stack_a, t_list **stack_b);
void	sortelse(t_list **stack_a, t_list **stack_b);
void	sort_min_extremes(t_list **stack_a, t_list **stack_b);
void	sort_max_extremes(t_list **stack_a, t_list **stack_b);
int		ft_find_place_a(t_list *stack_a, int num_push);
int		find_right_next(t_list **stack_a, t_list **stack_b);
void	rotate_push(t_list **stack_a, t_list **stack_b);
void	sort_pb(t_list **stack_a, t_list **stack_b);
void	get_cost(t_list	**stack);
int		rrr_cost(t_list *stack_a, t_list *stack_b, int cont);
t_list	*lower_cost(t_list *stack_a, t_list *stack_b);
void	return_to_a(t_list **stack_a, t_list **stack_b);
void	decision(t_list **stack_a, t_list **stack_b);
void	finish_rotation(t_list *move, t_list **stack_a, t_list **stack_b);
int		is_letter(char **str);
void	exit_error();

#endif