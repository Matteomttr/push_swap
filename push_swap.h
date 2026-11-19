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

# include <stdlib.h>
# include "src/libft/libft.h"

void	redirect(char *flag, t_list **stack_a, t_list **stack_b);
t_list	*get_tab(int argc, char **argv, char **flag);

#endif
