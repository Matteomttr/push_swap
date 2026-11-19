/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 08:58:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/19 18:14:40 by qumessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "src/libft/libft.h"
# include <stdlib.h>

void	redirect(char *flag, t_list **stack_a, t_list **stack_b);
t_list	*get_tab(int argc, char **argv, char **flag);
int		swap(t_list **lst);
int		dual_swap(t_list **a, t_list **b);
int		push(t_list **add, t_list **taken);
int		rotate(t_list **lst);
int		dual_rotate(t_list **a, t_list **b);
int		reverse_rotate(t_list **lst);
int		dual_reverse_rotate(t_list **a, t_list **b);

#endif
