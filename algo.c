/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:02:35 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/26 13:23:49 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	ft_printf("\nsatck a\n\n");
	while (i < info->content_length)
	{
		ft_printf("%d\n", *info->a[i]);
		i++;
	}
	ft_printf("\nsatck b\n\n");
	i = 0;
	while (i < info->count_b)
	{
		ft_printf("%d\n", *info->b[i]);
		i++;
	}
}

void	free_content(t_list *info)
{
	int	i;

	i = 0;
	while (i < info->content_length)
	{
		free(info->content[i]);
		i++;
	}
	free(info->content);
}
