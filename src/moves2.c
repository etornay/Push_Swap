/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:05 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/28 15:47:00 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int flag)
{
	t_list	*aux;

	if (data->stack_a == NULL)
		return ;
	aux = data->stack_a;
	data->stack_a = data->stack_a->next;
	aux->next = NULL;
	ft_lstadd_back(&data->stack_a, aux);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_data *data, int flag)
{
	t_list	*aux;

	if (data->stack_b == NULL)
		return ;
	aux = data->stack_b;
	data->stack_b = data->stack_b->next;
	aux->next = NULL;
	ft_lstadd_back(&data->stack_b, aux);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_data *data, int flag)
{
	ra(data, 0);
	rb(data, 0);
	if (flag == 1)
		ft_printf("rr\n");
}

