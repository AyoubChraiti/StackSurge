/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:02:34 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/14 09:40:32 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_list
{
	int		**a;
	int		**b;
	char	**content;
	char	*cont;
	int		count_b;
	int		content_length;
}			t_list;

void	print_exit(void);
int		check_dup(t_list *info);
int		check_sign(char *s);
void	parse_stack(t_list *info);
void	print_stacks(t_list *info);
void	check_args(char *s);
void	sa(t_list *info);
void	sb(t_list *info);
void	pb(t_list *info);
void	ss(t_list *info);
void	ra(t_list *info);
void	rb(t_list *info);
void	rr(t_list *info);
void	pa(t_list *info);
void	rra(t_list *info);
void	rrb(t_list *info);
void	rrr(t_list *info);

void	push_swap(t_list *stacks);
void	push_back_and_arrange(t_list *stacks);
void	sort_three_elements(t_list *stacks);
void	sort_two_elements(t_list *stacks);

#endif