/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:09:13 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/19 10:44:47 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static float	compute_disorder(t_list *stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*i;
	t_list	*j;

	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs += 1.0;
			if (i->content > j->content)
				mistakes += 1.0;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0f);
	return (mistakes / total_pairs);
}

static void	adaptive_select(t_list **stack_a, t_list **stack_b, float disorder)
{
	ft_printf("Algorithme Adaptive choisi (--adaptive or void)\nCalcul de la complexité : %d%%\n", (int)(disorder * 100));
	if (disorder < 0.2)
		ft_printf("Algorithme simple choisi en O(n**2) (--simple)\n");
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_printf("Algorithme medium choisi en O(n sqrt(n)) (--medium)\n");
	else if (disorder >= 0.5)
		ft_printf("Algorithme complex choisi en O(n log n) (--complex)\n");
}

void	redirect(char *flag, t_list **stack_a, t_list **stack_b)
{
	float	disorder;

	disorder = compute_disorder(*stack_a);
	if (disorder == 0.0)
		ft_printf("Error: the list is already sorted.\n");
	else if (disorder > 1.0 || disorder < 0.0)
		ft_printf("Error\n");
	else if (!ft_strcmp(flag, "--simple"))
		ft_printf("Algorithme simple choisi en O(n**2) (--simple)\n");
	else if (!ft_strcmp(flag, "--medium"))
		ft_printf("Algorithme medium choisi en O(n sqrt(n)) (--medium)\n");
	else if (!ft_strcmp(flag, "--complex"))
		ft_printf("Algorithme complex choisi en O(n log n) (--complex)\n");
	else
		adaptive_select(&*stack_a, &*stack_b, disorder);
	return ;
}
