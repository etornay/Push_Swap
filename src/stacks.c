/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:03 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/22 15:17:26 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lee(t_data *data)
{
	t_list	*x;
	t_list	*y;

	x = data->stack_a;
	y = data->stack_b;
	ft_printf("Stack a :\n");
	while (x != NULL)
	{
		ft_printf("Valor = %d Indice = %d Pos = %d TPos = %d Cost_b = %d Cost_a = %d \n", x->value, x->index, x->pos, x->target_pos, x->cost_b, x->cost_a);
		x = x->next;
	}
	ft_printf("Stack b :\n");
	while (y != NULL)
	{
		ft_printf("Valor = %d Indice = %d Pos = %d TPos = %d Cost_b = %d Cost_a = %d \n", y->value, y->index, y->pos, y->target_pos, y->cost_b, y->cost_a);
		y = y->next;
	}
	return (EXIT_SUCCESS);
}

int	repeat(t_data *data, long long int n)
{
	t_list	*aux;

	aux = data->stack_a;
	if ((n > MAX_INT) || (n < MIN_INT))
		return (EXIT_FAILURE);
	while (aux != NULL)
	{
		if (n == (long long int)aux->value)
			return (EXIT_FAILURE);
		aux = aux->next;
	}
	return (EXIT_SUCCESS);
}

long long int	ft_atol(const char *str)
{
	long long int	num;
	unsigned int	i;
	long long int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

int	init_stack_a(t_data *data)
{
	int				i;
	long long int	n;
	t_list			*node;

	i = 0;
	while (data->arg[i] != NULL)
	{
		n = ft_atol(data->arg[i]);
		if (repeat(data, n) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		node = ft_lstnew(n, 0, 0, 0);
		ft_lstadd_back(&data->stack_a, node);
		i++;
	}
	return (EXIT_SUCCESS);
}
