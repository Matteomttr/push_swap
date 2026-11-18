/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:44:03 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 16:59:00 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_isdigit(char *tab)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		if (tab[j] != ' ' && !(tab[j] >= '0' && tab[j] <= '9'))
			return (1);
		j++;
	}
	return (0);
}

static char	*fill_tab(int argc, char **argv, int i)
{
	char	*tmp;
	char	*tab;

	tmp = NULL;
	tab = NULL;
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

t_list	*get_tab(int argc, char **argv, char **flag)
{
	t_list	*new_stack;
	int		i;
	char	*tab;

	i = 1;
	if (argv[i][0] == '-' && argv[i][1] == '-')
	{
		*flag = argv[1];
		i++;
	}
	tab = fill_tab(argc, argv, i);
	if (ft_isdigit(tab))
	{
		free(tab);
		ft_printf("Error");
		return (NULL);
	}
	new_stack = ft_split(tab, ' ');
	free(tab);
	return (new_stack);
}
