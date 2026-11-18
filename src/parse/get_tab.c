/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:44:03 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 14:16:24 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static char	*fill_tab(int argc, char **argv, int i)
{
	char	*tmp;
	char	*tab;

	if (argc != 2 + i)
	{
		while (argv[i])
		{
			tmp = ft_strjoin(tab, argv[i]);
			free(tab);
			tab = tmp;
			tmp = ft_strjoin(tab, " ");
			free(tab);
			tab = tmp;
			i++;
		}
	}
	else
		tab = argv[i];
	return (tab);
}

int	*get_tab(int argc, char **argv, char **flag)
{
	int		*new_stack;
	int		i;
	int		j;
	char	*tab;

	i = 1;
	j = 0;
	if (argv[i][0] == '-' && argv[i][1] == '-')
	{
		*flag = argv[1];
		i++;
	}
	tab = fill_tab(argc, argv, i);
	while (tab[j])
	{
		if (!ft_isdigit(tab[j]))
			return (NULL);
		j++;
	}
	new_stack = ft_split(tab, ' ');
	return (new_stack);
}
