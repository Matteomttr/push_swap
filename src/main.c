/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 09:47:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 16:37:17 by mamatter         ###   ########.fr       */
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
	stack_a = get_tab(argc, argv, &flag);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->content);
		stack_b = stack_a;
		stack_a = stack_a->next;
		free(stack_b);
	}
	return (0);
}
