/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:14:57 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/28 18:00:31 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_data
{
	char	**arg;
	int		i;
	int		flag;
	t_list	*aux;
	t_list	*a;
	t_list	*b;
	t_list	*max;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

int		check_arg_split(char **argv, t_data *data);
int		check_arg(char **argv, t_data *data);
int		init_stack_a(t_data *data);
void	set_index(t_data *data);
int		check_order(t_data *data);
int		repeat_numbers(t_data *data);
void	pa(t_data *data, int flag);
void	pb(t_data *data, int flag);
void	sa(t_data *data, int flag);
void	sb(t_data *data, int flag);
void	ss(t_data *data, int flag);
void	ra(t_data *data, int flag);
void	rb(t_data *data, int flag);
void	rr(t_data *data, int flag);
void	rra(t_data *data, int flag);
void	rrb(t_data *data, int flag);
void	rrr(t_data *data, int flag);
void	sort_values(t_data *data);
void	values_3(t_data *data);
void	pos_stacks(t_data *data);
void	tpos_stacks(t_data *data);
void	cost_b(t_data *data);
void	cost_a(t_data *data);
int		ft_abs(int cost);
int		total_cost(t_list *node);
t_list	*cheapest_cost(t_data *data);
void	final_moves(t_data *data);
void	final_moves2(t_data *data);
void	last_step(t_data *data);
void	lst_print_structs(t_list **lst_a, t_list **lst_b);
void	free_arg(char **arg);

#endif