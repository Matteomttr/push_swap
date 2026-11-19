/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumessen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:44:45 by qumessen          #+#    #+#             */
/*   Updated: 2026/11/19 17:57:52 by qumessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	return (1);
}

int	dual_swap(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	return (1);
}

// #include <stdio.h>
// #include <stdbool.h>
//
// int	main(void)
// {
// t_list	c = {30, NULL};
// t_list	b = {20, &c};
// t_list	a = {10, &b};
// t_list	*lst = &a;
//
//
// t_list	c2 = {30, NULL};
// t_list	b2 = {20, &c2};
// t_list	a2 = {10, &b2};
// t_list	*lst2 = &a2;
// swap(&lst);
// swap(&lst2);
// dual_swap(&lst, &lst2)
// while (true)
// {
// printf("%d, ", lst->nbr);
// lst = lst->next;
// if (lst->next == NULL)
// {
// printf("%d, ", lst->nbr);
// printf("NULL");
// break ;
// }
// }
// printf("\n");
// while (true)
// {
// printf("%d, ", lst2->nbr);
// lst2 = lst2->next;
// if (lst2->next == NULL)
// {
// printf("%d, ", lst2->nbr);
// printf("NULL");
// break ;
// }
// }
// return (0);
// }
