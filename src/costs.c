/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:13:59 by etornay-          #+#    #+#             */
/*   Updated: 2024/01/02 13:15:00 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*cheapest_cost(t_data *data)
{
	t_list	*cheap;
	t_list	*aux;

	aux = data->stack_b;
	cheap = NULL;
	while (aux != NULL)
	{
		if (cheap == NULL || total_cost(aux) < total_cost(cheap))
			cheap = aux;
		aux = aux->next;
	}
	return (cheap);
}

int	total_cost(t_list *node)
{
	int	total_cost;

	total_cost = 0;
	if (node->cost_a >= 0 && node->cost_b >= 0)
	{
		if (node->cost_a > node->cost_b)
			total_cost = node->cost_a;
		else if (node->cost_a < node->cost_b)
			total_cost = node->cost_b;
		else
			total_cost = node->cost_a;
	}
	else if (node->cost_a <= 0 && node->cost_b <= 0)
	{
		if (node->cost_a > node->cost_b)
			total_cost = node->cost_b * -1;
		else if (node->cost_a < node->cost_b)
			total_cost = node->cost_a * -1;
		else
			total_cost = node->cost_a * -1;
	}
	else if ((node->cost_a >= 0 && node->cost_b <= 0)
		|| (node->cost_a <= 0 && node->cost_b >= 0))
		total_cost = ft_abs(node->cost_a) + ft_abs(node->cost_b);
	return (total_cost);
}

int	ft_abs(int cost)
{
	if (cost < 0)
		cost = cost * -1;
	return (cost);
}

void	cost_b(t_data *data)
{
	int		mid;
	int		size;
	t_list	*b;

	b = data->stack_b;
	size = ft_lstsize(b);
	if (size % 2 != 0)
		mid = size / 2 + 1;
	else
		mid = size / 2;
	while (b != NULL)
	{
		if (b->pos <= mid)
			b->cost_b = b->pos - 1;
		else if (b->pos > mid)
			b->cost_b = (size - b->pos + 1) * -1;
		b = b->next;
	}
}

void	cost_a(t_data *data)
{
	int		mid_a;
	int		mid_b;
	int		size_b;
	int		size_a;

	data->a = data->stack_a;
	data->b = data->stack_b;
	size_a = ft_lstsize(data->a);
	size_b = ft_lstsize(data->b);
	if (size_a % 2 != 0)
		mid_a = size_a / 2 + 1;
	else
		mid_a = size_a / 2;
	if (size_b % 2 != 0)
		mid_b = size_b / 2 + 1;
	else
		mid_b = size_b / 2;
	while (data->b != NULL)
	{
		if (data->b->target_pos <= mid_a)
			data->b->cost_a = data->b->target_pos - 1;
		else if (data->b->target_pos > mid_a)
			data->b->cost_a = (size_a - data->b->target_pos + 1) * -1;
		data->b = data->b->next;
	}
}
