/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 08:58:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 20:12:06 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "src/libft/ft_printf/ft_printf.h"

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
int		*ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

int		*get_tab(int argc, char **argv, char **flag);

#endif
