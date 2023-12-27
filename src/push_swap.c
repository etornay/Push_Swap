/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:32:52 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/27 17:59:40 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main2(t_data *data)
{
	init_stack_a(data);
	set_index(data);
	if (check_order(data) == EXIT_SUCCESS)
		return (ft_printf("Numeros ordenados\n"), EXIT_SUCCESS);
	sort_values(data);
	//lee(data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		if (check_arg_split(argv, data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		if (check_arg(argv, data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (0);
	i = 0;
	if (main2(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
}
