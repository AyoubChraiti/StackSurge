/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:22:19 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/27 00:00:12 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list *info)
{
	int	*tmp;

	if (info->content_length <= 2)
		return ;
	tmp = info->a[0];
	info->a[0] = info->a[1];
	info->a[1] = tmp;
}

void	sb(t_list *info)
{
	int	*tmp;

	if (info->count_b <= 2)
		return ;
	tmp = info->b[0];
	info->b[0] = info->b[1];
	info->b[1] = tmp;
}

void	ss(t_list *info)
{
	int	*tmp;
	int	*tmp2;

	if (info->content_length <= 2 && info->count_b <= 2)
		return ;
	tmp = info->b[0];
	info->b[0] = info->b[1];
	info->b[1] = tmp;
	tmp2 = info->a[0];
	info->a[0] = info->a[1];
	info->a[1] = tmp2;
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
	}
}
