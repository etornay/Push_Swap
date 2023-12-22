/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:14:03 by etornay-          #+#    #+#             */
/*   Updated: 2023/12/19 14:23:37 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int value, int index, int pos, int target_pos)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->value = value;
	new_lst->index = index;
	new_lst->pos = pos;
	new_lst->target_pos = target_pos;
	new_lst->cost_a = 0;
	new_lst->cost_b = 0;
	new_lst->next = NULL;
	return (new_lst);
}
