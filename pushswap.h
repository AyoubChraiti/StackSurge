/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:02:34 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/22 16:13:22 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
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

typedef struct	s_match
{
    int	index_b;
    int	index_a;
    int	cost;
}			t_match;

void		print_exit(void);
int			check_dup(t_list *info);
int			check_sign(char *s);
void		parse_stack(t_list *info);
void		print_stacks(t_list *info);
void		check_args(char *s);
void		initialize_t_list(char *s, t_list *info);
void		sa(t_list *info);
void		sb(t_list *info);
void		pb(t_list *info);
void		ss(t_list *info);
void		ra(t_list *info);
void		rb(t_list *info);
void		rr(t_list *info);
void		pa(t_list *info);
void		rra(t_list *info);
void		rrb(t_list *info);
void		rrr(t_list *info);
t_match 	find_cheapest_match(t_list *stacks);
void		push_swap(t_list *stacks);
void		sort_three_elements(t_list *stacks);
void		sort_two_elements(t_list *stacks);
int			calculate_cost(t_list *stacks, int index_b, int index_a);
int			find_smallest_bigger(t_list *stacks, int num);
int			process_instruction(char *instruction, t_list *x);
int			is_sorted(t_list *stacks);
void		rotate_until_b(t_list *stacks, int index);
void		rotate_smallest_to_top(t_list *stacks);
void		rotate_until_a(t_list *stacks, int index);

#endif