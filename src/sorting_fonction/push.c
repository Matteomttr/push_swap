/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumessen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:06:25 by qumessen          #+#    #+#             */
/*   Updated: 2026/11/19 17:57:43 by qumessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

int	push(t_list **add, t_list **taken)
{
	t_list	*tmp;

	if (!*taken)
		return (0);
	tmp = *taken;
	*taken = (*taken)->next;
	tmp->next = *add;
	*add = tmp;
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
// t_list	c2 = {70, NULL};
// t_list	b2 = {60, &c2};
// t_list	a2 = {50, &b2};
// t_list	*lst2 = &a2;
//
//
// push(&lst, &lst2);
//
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
