/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:06 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/28 18:00:01 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repeat_numbers(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (data->arg[i] != NULL)
	{
		j = 0;
		while (data->arg[j] != NULL)
		{
			if (ft_atoi(data->arg[i]) == ft_atoi(data->arg[j]))
				flag++;
			j++;
		}
		if (flag > 1)
			return (ft_printf("Error: Repetidos\n"), EXIT_FAILURE);
		flag = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	free_arg(char **arg)
{
	int	i;

	if (arg != NULL)
	{
		i = 0;
		while (arg[i] != NULL)
		{
			free(arg[i]);
			i++;
		}
		free(arg);
		arg = NULL;
	}
}

int	check_arg2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->arg[++i] != NULL)
	{
		j = -1;
		while (data->arg[i][++j] != '\0')
		{
			if (data->arg[i][j] == '-')
				j++;
			if (ft_isdigit(data->arg[i][j]) == '\0')
			{
				ft_printf("Error: Argumento no numérico\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	check_arg(char **argv, t_data *data)
{
	data->arg = argv + 1;
	if (data->arg == NULL)
		exit (EXIT_FAILURE);
	if (data->arg[0] == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (repeat_numbers(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	check_arg2(data);
	return (EXIT_SUCCESS);
}

int	check_arg_split(char **argv, t_data *data)
{
	int	i;
	int	j;

	if (argv[1] != NULL)
	{
		data->arg = ft_split(argv[1], ' ');
		if (data->arg == NULL)
			return (EXIT_FAILURE);
		if (data->arg[0] == NULL)
			return (free_arg(data->arg), ft_printf("Error: Incorrecto\n"), 1);
		i = -1;
		while (data->arg[++i] != NULL)
		{
			j = -1;
			while (data->arg[i][++j] != '\0')
			{
				if (data->arg[i][j] == '-')
					j++;
				if (ft_isdigit(data->arg[i][j]) == '\0')
					return (free_arg(data->arg), ft_printf("Error: Nulo\n"), 1);
			}
		}
	}
	return (EXIT_SUCCESS);
}
