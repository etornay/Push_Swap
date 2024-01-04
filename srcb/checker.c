/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:58:15 by etornay-          #+#    #+#             */
/*   Updated: 2024/01/04 14:19:22 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/* void	ft_leaks(void)
{
	system("leaks -q checker");
}atexit(ft_leaks); */

void	init_data(t_data *data)
{
	data->arg = NULL;
	data->i = 0;
	data->flag = 0;
	data->split_flag = 0;
	data->aux = NULL;
	data->a = NULL;
	data->b = NULL;
	data->max = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

int	check(char **line, t_data *data)
{
	if (!ft_strncmp(*line, "pb\n", 3))
		return (pb(data, 0), 0);
	else if (!ft_strncmp(*line, "pa\n", 3))
		return (pa(data, 0), 0);
	else if (!ft_strncmp(*line, "sa\n", 3))
		return (sa(data, 0), 0);
	else if (!ft_strncmp(*line, "sb\n", 3))
		return (sb(data, 0), 0);
	else if (!ft_strncmp(*line, "ss\n", 3))
		return (ss(data, 0), 0);
	else if (!ft_strncmp(*line, "ra\n", 3))
		return (ra(data, 0), 0);
	else if (!ft_strncmp(*line, "rb\n", 3))
		return (rb(data, 0), 0);
	else if (!ft_strncmp(*line, "rr\n", 3))
		return (rr(data, 0), 0);
	else if (!ft_strncmp(*line, "rra\n", 3))
		return (rra(data, 0), 0);
	else if (!ft_strncmp(*line, "rrb\n", 3))
		return (rrb(data, 0), 0);
	else if (!ft_strncmp(*line, "rrr\n", 3))
		return (rrr(data, 0), 0);
	return (EXIT_FAILURE);
}

int	main2(t_data *data)
{
	char	*line;

	if (init_stack_a(data) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	set_index(data);
	line = get_next_line(0);
	while (line)
	{
		if (check(&line, data) == 1)
		{
			ft_printf("Error\n");
			exit (EXIT_FAILURE);
		}
		else
		{
			free (line);
			line = get_next_line(0);
		}
	}
	if (order_stack_a(data) == 0 && data->stack_b == NULL)
		return (ft_printf("OK\n"), EXIT_SUCCESS);
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
