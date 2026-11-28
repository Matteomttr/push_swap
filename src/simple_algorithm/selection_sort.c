/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumessen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:30:31 by qumessen          #+#    #+#             */
/*   Updated: 2026/11/28 18:32:11 by qumessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"
#include <stdio.h>
#include <stdbool.h>

void	print_lst(t_list *lst)
{
	while (1)
	{
		printf("%d\n, ", lst->content);
		lst = lst->next;
		if (lst->next == NULL)
		{
			printf("%d\n, ", lst->content);
			printf("NULL");
			break ;
		}
	}
	printf("\n");
}

size_t	long_sort(t_list **lst, t_list **lst2, t_list *less)
{
	size_t	count;
	t_list	*tmp;

	count = 0;
	tmp = *lst;
	while (tmp->next != less)
	{
		tmp = tmp->next;
		count += push(lst2, lst);
	}
	count += swap(lst);
	while ((*lst2)->next)
	{
		count += push(lst, lst2);
		if ((*lst)->content > less->content)
			count += swap(lst);
	}
	return (count);
}

int	lst_is_sort(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

size_t	selection_sort(t_list **lst, t_list **lst2)
{
	size_t	count;
	t_list	*tmp;
	t_list	*less;

	count = 0;
	tmp = *lst;
	while (!lst_is_sort(*lst))
	{
		less = tmp;
		while (tmp)
		{
			if (tmp->content < less->content)
				less = tmp;
			tmp = tmp->next;
		}
		tmp = *lst;
		while (tmp->content < tmp->next->content)
			tmp = tmp->next;
		if (less == (*lst)->next)
			count += swap(lst);
		else if (less != tmp)
			count += long_sort(lst, lst2, less);
	}
	return (count);
}

int	main(void)
{
	t_list	n20 = {NULL, 742, &n21};
	t_list	n19 = {NULL, 365, &n20};
	t_list	n18 = {NULL, 597, &n19};
	t_list	n17 = {NULL, 189, &n18};
	t_list	n16 = {NULL, 592, &n17};
	t_list	n15 = {NULL, 175, &n16};
	t_list	n14 = {NULL, 673, &n15};
	t_list	n13 = {NULL, 140, &n14};
	t_list	n12 = {NULL, 304, &n13};
	t_list	n11 = {NULL, 946, &n12};
	t_list	n10 = {NULL, 73, &n11};
	t_list	n9 = {NULL, 587, &n10};
	t_list	n8 = {NULL, 713, &n9};
	t_list	n7 = {NULL, 906, &n8};
	t_list	n6 = {NULL, 416, &n7};
	t_list	n5 = {NULL, 115, &n6};
	t_list	n4 = {NULL, 900, &n5};
	t_list	n3 = {NULL, 683, &n4};
	t_list	n2 = {NULL, 848, &n3};
	t_list	n1 = {NULL, 164, &n2};
	t_list	*a = &n1;
	t_list *b;
	b = malloc(sizeof(t_list) * 10);
	printf("COUNT : [%zu]\n", selection_sort(&a, &b));
	print_lst(a);
	return (0);
}
