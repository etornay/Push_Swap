/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:32:52 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/28 18:01:26 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	del_content(int content)
{
	content = 0;
}

int	main2(t_data *data)
{
	t_list	*aux;

	if (repeat_numbers(data) == EXIT_FAILURE)
		return (free_arg(data->arg), EXIT_FAILURE);
	init_stack_a(data);
	set_index(data);
	if (check_order(data) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	aux = data->stack_a;
	if (ft_lstsize(aux) == 2)
		return (sa(data, 1), EXIT_SUCCESS);
	else if (ft_lstsize(aux) == 3)
		return (values_3(data), EXIT_SUCCESS);
	sort_values(data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	atexit(ft_leaks);
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (free(data), EXIT_FAILURE);
	if (argc == 2)
	{
		if (check_arg_split(argv, data) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		if (check_arg(argv, data) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else
		return (free(data), 0);
	i = 0;
	if (main2(data) == EXIT_FAILURE)
		return (free(data), EXIT_FAILURE);
	free_arg(data->arg);
	return (ft_lstclear(&data->stack_a, &del_content),
		ft_lstclear(&data->stack_b, &del_content), free(data), EXIT_SUCCESS);
}
