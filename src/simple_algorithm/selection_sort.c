/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumessen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:30:31 by qumessen          #+#    #+#             */
/*   Updated: 2026/11/23 18:36:07 by qumessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"
#include <stdio.h>
#include <stdbool.h>
void	long_sort(t_list **a, t_list **b, t_list *tmp, t_list *less)
{
	while (tmp->next != less)
	{
		tmp = tmp->next;
		push(b, a);
	}
	swap(a);
	while ((*b)->next != NULL)
	{
		push(a, b);
		swap(a);
	}
}

int	selection_sort(t_list **a, t_list **b)
{
	t_list	*less;
	t_list	*tmp;
	size_t	i;

	i = 0;
	less = *a;
	tmp = *a;
	while (i != 2)
	{
		less = *a + i;
		while (tmp->next != NULL)
		{
			if (tmp->content < less->content)
				less = tmp;
			tmp = tmp->next;
		}
		tmp = *a + i++;
		if (less == *a + 1)
			swap(a);
		else
			long_sort(a, b, tmp, less);
	}
	return (1);
}

int	main(void)
{
	t_list	e = {40, NULL};
	t_list	d = {10, &e};
	t_list	c = {30, &d};
	t_list	b = {20, &c};
	t_list	a = {50, &b};
	t_list	*lst = &a;
	t_list	*lst2 = malloc(sizeof(t_list) * 10);

	selection_sort(&lst, &lst2);

	while (true)
	{
		printf("%d, ", lst->content);
		lst = lst->next;
		if (lst->next == NULL)
		{
			printf("%d, ", lst->content);
			printf("NULL");
			break;
		}
	}
}
