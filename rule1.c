/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:23:52 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/26 23:41:37 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list *info)
{
	int	*tmp;

	if (info->content_length >= 2)
	{
		tmp = info->a[0];
		info->a[0] = info->a[1];
		info->a[1] = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list *info)
{
	int	*tmp;

	if (info->count_b >= 2)
	{
		tmp = info->b[0];
		info->b[0] = info->b[1];
		info->b[1] = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_list *info)
{
	int	*tmp;
	int	*tmp2;

	if (info->content_length >= 2 && info->count_b >= 2)
	{
		tmp = info->b[0];
		info->b[0] = info->b[1];
		info->b[1] = tmp;
		tmp2 = info->a[0];
		info->a[0] = info->a[1];
		info->a[1] = tmp2;
		write(1, "ss\n", 3);
	}
}

void	pa(t_list *info)
{
	int	i;

	if (info->count_b > 0)
	{
		i = info->content_length;
		while (i > 0)
		{
			info->a[i] = info->a[i - 1];
			i--;
		}
		info->a[0] = info->b[0];
		info->content_length++;
		info->count_b--;
		i = 0;
		while (i < info->count_b)
		{
			info->b[i] = info->b[i + 1];
			i++;
		}
		write(1, "pa\n", 3);
	}
}

void	pb(t_list *info)
{
	int	i;

	if (info->content_length > 0)
	{
		i = info->count_b;
		while (i > 0)
		{
			info->b[i] = info->b[i - 1];
			i--;
		}
		info->b[0] = info->a[0];
		info->count_b++;
		info->content_length--;
		i = 0;
		while (i < info->content_length)
		{
			info->a[i] = info->a[i + 1];
			i++;
		}
		write(1, "pb\n", 3);
	}
}
