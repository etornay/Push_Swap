/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:24 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/27 17:48:30 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_moves2(t_data *data)
{
	while (data->stack_b->cost_b > 0)
	{
		rb(data, 1);
		data->aux->cost_b--;
	}
	while (data->stack_b->cost_a > 0)
	{
		ra(data, 1);
		data->aux->cost_a--;
	}
	while (data->stack_b->cost_b < 0)
	{
		rrb(data, 1);
		data->aux->cost_b++;
	}
	while (data->stack_b->cost_a < 0)
	{
		rra(data, 1);
		data->aux->cost_a++;
	}
}

void	final_moves(t_data *data)
{
	data->aux = data->stack_b;
	/* if (total_cost(data->a) > total_cost(data->a->next) + 1
		&& data->a->index > data->a->next->index)
		sa(data, 1); */
	while (data->stack_b->cost_a > 0 && data->stack_b->cost_b > 0)
	{
		rr(data, 1);
		data->aux->cost_a--;
		data->aux->cost_b--;
	}
	while (data->stack_b->cost_a < 0 && data->stack_a->cost_b < 0)
	{
		rrr(data, 1);
		data->aux->cost_a++;
		data->aux->cost_b++;
	}
	final_moves2(data);
	pa(data, 1);
}

void	last_step(t_data *data)
{
	int		mid;
	t_list	*aux;

	mid = (ft_lstsize(data->stack_a) / 2) + 1;
	aux = data->stack_a;
	if (data->stack_a->index >= mid)
	{
		while (aux->index != 1)
		{
			ra(data, 1);
			aux = data->stack_a;
		}
	}
	else
	{
		while (aux->index != 1)
		{
			rra(data, 1);
			aux = data->stack_a;
		}
	}
}
