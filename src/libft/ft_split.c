/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:24:35 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 15:19:05 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(1 * sizeof(char));
		return (sub);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}

static int	ft_count_word(char const *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (len);
}

static int	*ft_free_all(int *lst, int size)
{
	while (size > 0)
	{
		size--;
		free(ft_itoa(lst[size]));
	}
	free(lst);
	return (NULL);
}

static int	*ft_fill(int *lst, char const *s, char c, int i)
{
	int	start;
	int	a;

	a = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i += 1;
			lst[a] = ft_atoi(ft_substr(s, start, i - start));
			if (!lst[a])
			{
				lst = ft_free_all(lst, a);
				return (NULL);
			}
			a++;
		}
		else
			i += 1;
	}
	return (lst);
}

t_list	*ft_split(char const *s, char c)
{
	t_list	*lst;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	lst = malloc((ft_count_word(s, c) + 1) * sizeof(int *));
	if (!lst)
		return (NULL);
	lst = ft_fill(lst, s, c, i);
	return (lst);
}

t_list	*ft_chainedsplit(char const *s, char c)
