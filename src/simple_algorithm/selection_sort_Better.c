/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_Better.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumessen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:30:31 by qumessen          #+#    #+#             */
/*   Updated: 2026/11/28 19:43:40 by qumessen         ###   ########.fr       */
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

size_t	long_sort(t_list **a, t_list **b, long int less)
{
	size_t	count;
	t_list	*tmp;

	count = 0;
	tmp = *a;
	if (less > 0)
	{
		while (less--)
			count += rotate(a);
	}
	else
	{
		less = less *-1;
		while (less--)
			count += rotate(a);
	}
	count += push(b, a);
	return (count);
}


// trouve la plus petite valeur de la liste, renvoie sont index (en negatif si elle se trouve a plus de la moitier de la liste complete)
long int	take_less(t_list *tmp)
{
	long int	i;
	long int	j;
	long int	less;

	i = 0;
	j = 0;
	less = tmp->content;
	while (tmp)
	{
		if (tmp->content < less)
		{
			less = tmp->content;
			i = j;
		}
		tmp = tmp->next;
		j++;
	}
	if (i > j / 2)
		i = i * -1;
	return (i);
}
size_t	selection_sort(t_list **a, t_list **b)
{
	size_t	count;
	t_list	*tmp;

	count = 0;
	tmp = *a;
	while ((*a)->next->next != NULL)
		count += long_sort(a, b, long_sort(a, b, take_less(*a)));
	return (count);
}

int	main(void)
{
	t_list	n20 = {NULL, 742, NULL};
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
	b = malloc(sizeof(t_list) * 100);
	printf("COUNT : [%zu]\n", selection_sort(&a, &b));
	print_lst(a);
	return (0);
}
