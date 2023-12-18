/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:06 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/18 12:08:55 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_arg(t_abeja *abeja)
{
	int	i;
	int	j;

	if (abeja->arg == NULL)
		return (EXIT_FAILURE);
	if (abeja->arg[0] == NULL)
		return (free_arg(abeja->arg), ft_printf("Error\n"), 1);
	i = -1;
	while (abeja->arg[++i] != NULL)
	{
		j = -1;
		while (abeja->arg[i][++j] != '\0')
		{
			if (abeja->arg[i][j] == '-')
				j++;
			if (ft_isdigit(abeja->arg[i][j]) == '\0')
				return (free_arg(abeja->arg), ft_printf("Error\n"), 1);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_arg_split(char **argv, t_abeja *abeja)
{
	int	i;
	int	j;

	if (argv[1] != NULL)
	{
		abeja->arg = ft_split(argv[1], ' ');
		if (abeja->arg == NULL)
			return (EXIT_FAILURE);
		if (abeja->arg[0] == NULL)
			return (free_arg(abeja->arg), ft_printf("Error\n"), 1);
		i = -1;
		while (abeja->arg[++i] != NULL)
		{
			j = -1;
			while (abeja->arg[i][++j] != '\0')
			{
				if (abeja->arg[i][j] == '-')
					j++;
				if (ft_isdigit(abeja->arg[i][j]) == '\0')
					return (free_arg(abeja->arg), ft_printf("Error\n"), 1);
			}
		}
	}
	return (EXIT_SUCCESS);
}
