/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 09:47:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 14:17:19 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	char	*flag;
	int		*stack_a;

	if (argc < 2)
		return (1);
	stack_a = get_tab(argc, argv, &flag);
	if (stack_a == NULL)
		return (1);
	int i = 0;
	while (stack_a[i])
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	return (0);
}
