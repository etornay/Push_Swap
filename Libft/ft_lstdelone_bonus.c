/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:20:08 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/19 14:31:10 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	del(lst->index);
	del(lst->pos);
	del(lst->target_pos);
	del(lst->cost_a);
	del(lst->cost_b);
	free(lst);
	lst = NULL;
}
