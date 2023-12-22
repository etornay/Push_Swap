/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:10 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/20 16:01:28 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data, int flag)
{
	t_list	*aux;

	if (data->stack_b == NULL)
		return ;
	aux = data->stack_b;
	data->stack_b = data->stack_b->next;
	ft_lstadd_front(&data->stack_a, aux);
	if (flag == 1)
		ft_printf("pa\n");
}

void	pb(t_data *data, int flag)
{
	t_list	*aux;

	if (data->stack_a == NULL)
		return ;
	aux = data->stack_a;
	data->stack_a = data->stack_a->next;
	ft_lstadd_front(&data->stack_b, aux);
	if (flag == 1)
		ft_printf("pb\n");
}

void	sa(t_data *data, int flag)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_a) < 2)
		return ;
	else
	{
		aux = data->stack_a;
		data->stack_a = data->stack_a->next;
		aux->next = data->stack_a->next;
		data->stack_a->next = aux;
	}
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_data *data, int flag)
{
	t_list	*aux;

	if (ft_lstsize(data->stack_b) < 2)
		return ;
	else
	{
		aux = data->stack_b;
		data->stack_b = data->stack_b->next;
		aux->next = data->stack_b->next;
		data->stack_b->next = aux;
	}
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_data *data, int flag)
{
	sa(data, 0);
	sb(data, 0);
	if (flag == 1)
		ft_printf("ss\n");
}
