/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:33:32 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/18 14:35:35 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_rev_int_tab(char *tab, int size)
{
	int		first;
	int		last;
	char	temp;

	first = 0;
	last = size - 1;
	while (first < last)
	{
		temp = tab[first];
		tab[first] = tab[last];
		tab[last] = temp;
		first++;
		last--;
	}
	return (tab);
}

static int	ft_nbrlen(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_reelitoa(char *str, int n, int *i, int len)
{
	if (n < 0)
		n = -n;
	while (*i < len)
	{
		if (n == 0)
			str[*i] = '0';
		else
			str[*i] = (n) % 10 + '0';
		n = n / 10;
		*i = *i + 1;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_nbrlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	str = ft_reelitoa(str, n, &i, len);
	if (n < 0)
		str[i - 1] = '-';
	str = ft_rev_int_tab(str, len);
	return (str);
}
