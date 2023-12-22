/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:41:13 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/21 15:01:53 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data, int flag)
{
	t_list	*aux;
	t_list	*aux_last;

	if (data->stack_a == NULL)
		return ;
	aux = data->stack_a;
	aux_last = ft_lstlast(data->stack_a);
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next = NULL;
	ft_lstadd_front(&data->stack_a, aux_last);
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_data *data, int flag)
{
	t_list	*aux;
	t_list	*aux_last;

	if (data->stack_b == NULL)
		return ;
	aux = data->stack_b;
	aux_last = ft_lstlast(data->stack_b);
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next = NULL;
	ft_lstadd_front(&data->stack_b, aux_last);
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_data *data, int flag)
{
	rra(data, 0);
	rrb(data, 0);
	if (flag == 1)
		ft_printf("rrr\n");
}
