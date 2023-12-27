/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:24:04 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/27 17:07:58 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_data *data)
{
	t_list	*counter;
	t_list	*little;
	int		aux;
	int		index;

	counter = data->stack_a;
	aux = MAX_INT;
	index = 1;
	while (index <= ft_lstsize(counter))
	{
		while (counter != NULL)
		{
			if (counter->value <= aux && counter->index == 0)
			{
				little = counter;
				aux = little->value;
			}
			counter = counter->next;
		}
		counter = data->stack_a;
		little->index = index;
		aux = MAX_INT;
		index++;
	}
}

int	check_order(t_data *data)
{
	t_list	*counter;
	int		index;

	counter = data->stack_a;
	index = 1;
	while (index <= ft_lstsize(data->stack_a))
	{
		if (counter->index == index)
		{
			counter = counter->next;
			index++;
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
