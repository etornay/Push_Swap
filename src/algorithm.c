/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:10:59 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/22 16:04:13 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_stack_a(t_data *data)
{
	t_list	*a;

	a = data->stack_a;
	while (a->next != NULL)
	{
		if (a->index < a->next->index)
			a = a->next;
		else if (a->index > a->next->index)
			return (1);
	}
	return (0);
}

void	tpos_stacks(t_data *data)
{
	t_list	*guti;

	data->b = data->stack_b;
	while (data->b != NULL)
	{
		data->a = data->stack_a;
		guti = NULL;
		data->max = NULL;
		while (data->a != NULL)
		{
			if (data->max == NULL || data->a->index > data->max->index)
				data->max = data->a;
			if (data->b->index < data->a->index
				&& (guti == NULL || data->a->index < guti->index))
				guti = data->a;
			data->a = data->a->next;
		}
		if (guti == NULL && order_stack_a(data) == 0)
			data->b->target_pos = 1;
		else if (guti == NULL)
			data->b->target_pos = data->max->pos + 1;
		else
			data->b->target_pos = guti->pos;
		data->b = data->b->next;
	}
}

void	pos_stacks(t_data *data)
{
	t_list	*counter;
	int		pos;

	counter = data->stack_a;
	pos = 1;
	while (pos <= ft_lstsize(data->stack_a))
	{
		counter->pos = pos;
		counter = counter->next;
		pos++;
	}
	counter = data->stack_b;
	pos = 1;
	while (pos <= ft_lstsize(data->stack_b))
	{
		counter->pos = pos;
		counter = counter->next;
		pos++;
	}
}

void	values_3(t_data *data)
{
	t_list	*aux;

	aux = data->stack_a;
	if (aux->next->index > aux->index
		&& aux->next->index > aux->next->next->index)
	{
		rra(data, 1);
		aux = data->stack_a;
		if (aux->index > aux->next->index)
			sa(data, 1);
	}
	else if (aux->index > aux->next->index
		&& aux->index > aux->next->next->index)
	{
		ra(data, 1);
		aux = data->stack_a;
		if (aux->index > aux->next->index)
			sa(data, 1);
	}
	else if (aux->index > aux->next->index
		&& aux->next->next->index > aux->index)
		sa(data, 1);
}

int	sort_values(t_data *data)
{
	t_list	*aux;

	aux = data->stack_a;
	if (ft_lstsize(aux) == 2)
		sa(data, 1);
	else if (ft_lstsize(aux) == 3)
	{
		values_3(data);
	}
	else
	{
		while (ft_lstsize(data->stack_a) > 3)
			pb(data, 1);
		values_3(data);
		pos_stacks(data);
		tpos_stacks(data);
		cost_b(data);
		cost_a(data);
	}
	return (EXIT_SUCCESS);
}