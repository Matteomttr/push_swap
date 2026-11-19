/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 09:47:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/19 10:53:09 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	char	*flag;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	flag = NULL;
	stack_a = get_tab(argc, argv, &flag);
	if (!stack_a)
		return (1);
	redirect(flag, &stack_a, &stack_b);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->content);
		stack_b = stack_a;
		stack_a = stack_a->next;
		free(stack_b);
	}
	return (0);
}
