/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 09:47:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 11:54:53 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	*ft_get_tab(int argc, char **argv, char **flag)
{
	int		*new_stack;
	int		i;
	int		j;
	char	*tmp_tab;
	char	*tmp;

	i = 1;
	j = 0;
	if (argv[i][0] == '-' && argv[i][1] == '-')
	{
		*flag = argv[1];
		i++;
	}
	if (argc != 2 + i)
	{
		while (argv[i])
		{
			tmp = ft_strjoin(tmp_tab, argv[i]);
			free(tmp_tab);
			tmp_tab = tmp;
			tmp = ft_strjoin(tmp_tab, " ");
			free(tmp_tab);
			tmp_tab = tmp;
			i++;
		}
	}
	else
		tmp_tab = argv[i];
	while (tmp_tab[j])
	{
		if (!ft_isdigit(ft_atoi(&tmp_tab[j])))
			return (NULL);
		j++;
	}
	new_stack = ft_split(tmp_tab, ' ');
	return (new_stack);
}

int	main(int argc, char **argv)
{
	char	*flag;
	int		*stack_a;

	if (argc < 2)
		return (1);
	stack_a = ft_get_tab(argc, argv, &flag);
	if (stack_a == NULL)
		return (1);
	int i = 0;
	while (stack_a[i])
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	return (0);
}
