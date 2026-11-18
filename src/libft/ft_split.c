/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:24:35 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 17:05:07 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	sub[i] = '\0';
	return (sub);
}

static int	ft_add_word(t_list **lst, char const *s, int start, int len)
{
	char	*word;
	t_list	*node;

	word = ft_substr(s, start, len);
	if (!word)
		return (0);
	node = ft_lstnew(ft_atoi(word));
	free(word);
	if (!node)
		return (0);
	ft_lstadd_back(lst, node);
	return (1);
}

t_list	*ft_split(char const *s, char c)
{
	t_list	*lst;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	lst = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!ft_add_word(&lst, s, start, i - start))
			{
				free(lst);
				return (NULL);
			}
		}
		else
			i++;
	}
	return (lst);
}
