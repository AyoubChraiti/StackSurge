/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:02:35 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/21 21:32:26 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two_elements(t_list *stacks)
{
	if (stacks->content_length == 2 && *stacks->a[0] > *stacks->a[1])
		sa(stacks);
}

void	sort_three_elements(t_list *stacks)
{
	if (stacks->content_length == 3)
	{
		if (*stacks->a[0] > *stacks->a[1] && *stacks->a[1] < *stacks->a[2]
			&& *stacks->a[0] < *stacks->a[2])
			sa(stacks);
		else if (*stacks->a[0] > *stacks->a[1] && *stacks->a[1] > *stacks->a[2])
		{
			sa(stacks);
			rra(stacks);
		}
		else if (*stacks->a[0] > *stacks->a[1] && *stacks->a[1] < *stacks->a[2]
			&& *stacks->a[0] > *stacks->a[2])
			ra(stacks);
		else if (*stacks->a[0] < *stacks->a[1] && *stacks->a[1] > *stacks->a[2]
			&& *stacks->a[0] < *stacks->a[2])
		{
			sa(stacks);
			ra(stacks);
		}
		else if (*stacks->a[0] < *stacks->a[1] && *stacks->a[1] > *stacks->a[2]
			&& *stacks->a[0] > *stacks->a[2])
			rra(stacks);
	}
}

void	print_stacks(t_list *info)
{
	int	i;

	i = 0;
	printf("\nsatck a\n\n");
	while (i < info->content_length)
	{
		ft_printf("%d\n", *info->a[i]);
		i++;
	}
	printf("\nsatck b\n\n");
	i = 0;
	while (i < info->count_b)
	{
		ft_printf("%d\n", *info->b[i]);
		i++;
	}
}
