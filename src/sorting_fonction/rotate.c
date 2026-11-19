/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumessen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:38:25 by qumessen          #+#    #+#             */
/*   Updated: 2026/11/19 17:57:56 by qumessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

int	rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *lst;
	*lst = (*lst)->next;
	tmp->next->next = NULL;
	return (1);
}

int	dual_rotate(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	return (1);
}

int	reverse_rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	return (1);
}

int	dual_reverse_rotate(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (1);
}

// #include <stdio.h>
// int	main(void)
// {
// t_list	e = {50, NULL};
// t_list	d = {40, &e};
// t_list	c = {30, &d};
// t_list	b = {20, &c};
// t_list	a = {10, &b};
// t_list	*lst = &a;
//
//
// t_list	c2 = {70, NULL};
// t_list	b2 = {60, &c2};
// t_list	a2 = {50, &b2};
// t_list	*lst2 = &a2;
//
//
// dual_reverse_rotate(&lst, &lst2);
// while (lst)
// {
// printf("%d, ", lst->nbr);
// lst = lst->next;
// if (!lst)
// printf("NULL");
// }
// printf("\n");
// while (lst2)
// {
// printf("%d, ", lst2->nbr);
// lst2 = lst2->next;
// if (!lst2)
// printf("NULL");
// }
// return (0);
// }
