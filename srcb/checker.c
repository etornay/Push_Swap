/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:58:15 by etornay-          #+#    #+#             */
/*   Updated: 2024/01/02 16:16:57 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	check(char **line, t_data *data)
{
	if (ft_strncmp(*line, "pa\n", 3))
		return (pa(data, 0), 0);
	else if (ft_strncmp(*line, "pb\n", 3))
		return (pb(data, 0), 0);
	else if (ft_strncmp(*line, "sa\n", 3))
		return (sa(data, 0), 0);
	else if (ft_strncmp(*line, "sb\n", 3))
		return (sb(data, 0), 0);
	else if (ft_strncmp(*line, "ss\n", 3))
		return (ss(data, 0), 0);
	else if (ft_strncmp(*line, "ra\n", 3))
		return (ra(data, 0), 0);
	else if (ft_strncmp(*line, "rb\n", 3))
		return (rb(data, 0), 0);
	else if (ft_strncmp(*line, "rr\n", 3))
		return (rr(data, 0), 0);
	else if (ft_strncmp(*line, "rra\n", 3))
		return (rra(data, 0), 0);
	else if (ft_strncmp(*line, "rrb\n", 3))
		return (rrb(data, 0), 0);
	else if (ft_strncmp(*line, "rrr\n", 3))
		return (rrr(data, 0), 0);
	return (EXIT_FAILURE);
}

int	main2(t_data *data)
{
	char	**line;

	if (init_stack_a(data) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	if (order_stack_a(data->stack_a) && data->stack_b == NULL)
		return (ft_printf("OK\n"), EXIT_SUCCESS);
	line = get_next_line(0);
	while (line != '\0')
	{
		if (check(&line, data) == EXIT_FAILURE)
			exit (EXIT_FAILURE);
		else
		{
			free (line);
			if (order_stack_a(data->stack_a) && data->stack_b == NULL)
				return (ft_printf("OK\n"), EXIT_SUCCESS);
			line = get_next_line(0);
		}
	}
	return (ft_printf("KO\n"), EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

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
		return (free(data), EXIT_FAILURE);
	if (main2(data) == EXIT_FAILURE)
		return (free(data), EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}
