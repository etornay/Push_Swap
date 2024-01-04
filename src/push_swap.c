/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:32:52 by etornay-          #+#    #+#             */
/*   Updated: 2024/01/04 14:20:13 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_leaks(void)
{
	system("leaks -q push_swap");
}atexit(ft_leaks); */

void	del_content(int content)
{
	content = 0;
}

int	main2(t_data *data)
{
	t_list	*aux;

	if (repeat_numbers(data) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (init_stack_a(data) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
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
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		exit (EXIT_FAILURE);
	if (argc == 2)
	{
		if (check_arg_split(argv, data) == EXIT_FAILURE)
			exit (EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		if (check_arg(argv, data) == EXIT_FAILURE)
			exit (EXIT_FAILURE);
	}
	else
		exit (EXIT_FAILURE);
	if (main2(data) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}
