/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:32:52 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/18 12:23:32 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_abeja	*abeja;

	abeja = ft_calloc(1, sizeof(t_abeja));
	if (abeja == NULL)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		if (check_arg_split(argv, abeja) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		if (check_arg(abeja) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (0);
}
