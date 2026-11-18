/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 09:47:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 18:20:27 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static float	compute_disorder(t_list *stack_a)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	t_list	*tmp;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < ft_lstsize(stack_a) - 1)
	{
		tmp = stack_a->next;
		total_pairs++;
		if (stack_a->content > tmp->content)
			mistakes++;
		i++;
	}
	return (mistakes / total_pairs);
}

static void	redirect(char *flag, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(flag, "--simple"))
		ft_printf("Algorithme simple choisi en O(n**2) (--simple)\n");
	else if (!ft_strcmp(flag, "--medium"))
		ft_printf("Algorithme medium choisi en O(n sqrt(n)) (--medium)\n");
	else if (!ft_strcmp(flag, "--complex"))
		ft_printf("Algorithme complex choisi en O(n log n) (--complex)\n");
	else
		ft_printf("Algorithme Adaptive choisi (--adaptive or void)\n calcul de la complexité : %f", compute_disorder(*stack_a));
	return ;
}

int	main(int argc, char **argv)
{
	char	*flag;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	flag = NULL;
	stack_a = get_tab(argc, argv, &flag);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->content);
		stack_b = stack_a;
		stack_a = stack_a->next;
		free(stack_b);
	}
	redirect(flag, &stack_a, &stack_b);
	return (0);
}
