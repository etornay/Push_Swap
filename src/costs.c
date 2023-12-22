/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:13:59 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/22 16:59:11 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*cheapest_cost(t_data *data)
{
	t_list	*result;
	t_list	*aux;

	aux = data->stack_b;
	result = NULL;
	while (aux != NULL)
	{
		if (result == NULL || total_cost(aux) < total_cost(result))
			result = aux;
		aux = aux->next;
	}
	resturn (result);
}

int	total_cost(t_list *node)
{
	int	total_cost;

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
	else if (node->cost_a > 0 && node->cost_b < 0
		|| node->cost_a < 0 && node->cost_b > 0)
		total_cost = abs(node->cost_a) + abs(node->cost_b);
	return (total_cost);
}

void	cost_b(t_data *data)
{
	int		mid;
	int		size;
	t_list	*b;

	b = data->stack_b;
	size = ft_lstsize(b);
	mid = size / 2 + 1;
	while (b != NULL)
	{
		if (b->pos <= mid)
		{
			b->cost_b = b->pos - 1;
		}
		else if (b->pos > mid)
		{
			b->cost_b = (size - b->pos + 1) * -1;
		}
		b = b->next;
	}
}

void	cost_a(t_data *data)
{
	int		mid;
	int		size;
	t_list	*b;

	b = data->stack_b;
	size = ft_lstsize(b);
	mid = size / 2 + 1;
	while (b != NULL)
	{
		if (b->target_pos <= mid)
		{
			b->cost_a = b->target_pos - 1;
		}
		else if (b->target_pos > mid)
		{
			b->cost_a = (size - b->target_pos + 1) * -1;
		}
		b = b->next;
	}
}
