/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:23:11 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/26 13:56:42 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_list *info)
{
	int	i;
	int	*tmp;

	if (info->content_length > 1)
	{
		tmp = info->a[0];
		i = 0;
		while (i < info->content_length - 1)
		{
			info->a[i] = info->a[i + 1];
			i++;
		}
		info->a[i] = tmp;
	}
}

void	rb(t_list *info)
{
	int	i;
	int	*tmp;

	if (info->count_b > 1)
	{
		tmp = info->b[0];
		i = 0;
		while (i < info->count_b - 1)
		{
			info->b[i] = info->b[i + 1];
			i++;
		}
		info->b[i] = tmp;
	}
}

void	rr(t_list *info)
{
	int	i;
	int	*tmp;

	if (info->count_b < 1 && info->content_length < 1)
		return ;
	tmp = info->a[0];
	i = 0;
	while (i < info->content_length - 1)
	{
		info->a[i] = info->a[i + 1];
		i++;
	}
	info->a[i] = tmp;
	tmp = info->b[0];
	i = 0;
	while (i < info->count_b - 1)
	{
		info->b[i] = info->b[i + 1];
		i++;
	}
	info->b[i] = tmp;
}

void	rra(t_list *info)
{
	int	*tmp;
	int	i;

	if (info->content_length > 1)
	{
		i = info->content_length - 1;
		tmp = info->a[info->content_length - 1];
		while (i > 0)
		{
			info->a[i] = info->a[i - 1];
			i--;
		}
		info->a[0] = tmp;
	}
}

void	rrb(t_list *info)
{
	int	*tmp;
	int	i;

	if (info->count_b > 1)
	{
		i = info->count_b - 1;
		tmp = info->b[info->count_b - 1];
		while (i > 0)
		{
			info->b[i] = info->b[i - 1];
			i--;
		}
		info->b[0] = tmp;
	}
}
