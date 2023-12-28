#include "push_swap.h"

void	lst_print_list_s(t_list *lst)
{
	int	num_len;

	num_len = ft_strlen(ft_itoa(lst->value));
	ft_printf("%i", lst->value);
	while (num_len < 3)
	{
		ft_printf(" ");
		num_len++;
	}
	ft_printf("    %i     %i ", lst->index, lst->pos);
	ft_printf("    %i    ", lst->target_pos);
	num_len = ft_strlen(ft_itoa(lst->cost_a));
	while (num_len < 3)
	{
		ft_printf(" ");
		num_len++;
	}
	ft_printf("%i   ", lst->cost_a);
	num_len = ft_strlen(ft_itoa(lst->cost_b));
	while (num_len < 3)
	{
		ft_printf(" ");
		num_len++;
	}
	ft_printf("%i\n", lst->cost_b);
}

void	lst_print_structs(t_list **lst_a, t_list **lst_b)
{
	t_list	*pos_a;
	t_list	*pos_b;

	pos_a = *lst_a;
	pos_b = *lst_b;
	ft_printf("\n** Stack A **\n");
	ft_printf("NUM   IND   POS   TAR   C-A   C-B\n");
	while (pos_a)
	{
		lst_print_list_s(pos_a);
		pos_a = pos_a->next;
	}
	ft_printf("\n** Stack B **\n");
	ft_printf("NUM   IND   POS   TAR   C-A   C-B\n");
	while (pos_b)
	{
		lst_print_list_s(pos_b);
		pos_b = pos_b->next;
	}
	ft_printf("\n");
}
