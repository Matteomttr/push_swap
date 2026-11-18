/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:06:08 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 17:54:27 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

size_t			ft_strlen(const char *s);
int				ft_atoi(const char *nptr);
char			*ft_strjoin(char const *s1, char const *s2);
t_list			*ft_split(char const *s, char c);
char			*ft_itoa(int n);
t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **lst, t_list *new_lst);
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_lst);

#endif
