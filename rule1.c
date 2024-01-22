/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:23:52 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/22 09:22:35 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list *info)
{
	int	tmp;

	if (info->content_length < 2)
		return ;
	tmp = *info->a[0];
	*info->a[0] = *info->a[1];
	*info->a[1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_list *info)
{
	int	tmp;

	if (info->count_b < 2)
		return ;
	tmp = *info->b[0];
	*info->b[0] = *info->b[1];
	*info->b[1] = tmp;
	ft_printf("sb\n");
}

void	ss(t_list *info)
{
	int	tmp;
	int	tmp2;

	if (info->content_length < 2 || info->count_b < 2)
		return ;
	tmp = *info->b[0];
	*info->b[0] = *info->b[1];
	*info->b[1] = tmp;
	tmp2 = *info->a[0];
	*info->a[0] = *info->a[1];
	*info->a[1] = tmp2;
	ft_printf("ss\n");
}

void	pa(t_list *info)
{
	int	i;

	i = 0;
	if (info->count_b > 0)
	{
		*info->a[info->content_length] = *info->b[0];
		info->content_length++;
		info->count_b--;
		while (i < info->count_b)
		{
			*info->b[i] = *info->b[i + 1];
			i++;
		}
	}
	ft_printf("pa\n");
}

void	pb(t_list *info)
{
	int	i;

	i = 0;
	if (info->content_length > 0)
	{
		*info->b[info->count_b] = *info->a[0];
		info->count_b++;
		info->content_length--;
		while (i < info->content_length)
		{
			*info->a[i] = *info->a[i + 1];
			i++;
		}
	}
	ft_printf("pb\n");
}
