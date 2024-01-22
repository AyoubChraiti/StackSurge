/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:14 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/22 17:30:30 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_list *info)
{
	int	tmp;
	int	i;

	if (info->count_b < 1 && info->content_length < 1)
		return ;
	i = info->content_length - 1;
	tmp = *info->a[info->content_length - 1];
	while (i > 0)
	{
		*info->a[i] = *info->a[i - 1];
		i--;
	}
	*info->a[0] = tmp;
	i = info->count_b - 1;
	tmp = *info->b[info->count_b - 1];
	while (i > 0)
	{
		*info->b[i] = *info->b[i - 1];
		i--;
	}
	*info->b[0] = tmp;
	ft_printf("rrr\n");
}

void	check_args(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			print_exit();
		i++;
	}
	i = 0;
	while(s[i])
	{
		if(ft_isdigit(s[i]))
			flag = 1;
		i++;
	}
	if(!flag)
		print_exit();
}

void	initialize_t_list(char *s, t_list *info)
{
	int	i;

	i = 0;
	info->count_b = 0;
	info->content = ft_split(s, ' ');
	info->a = (int **)malloc(sizeof(int *) * info->content_length);
	info->b = (int **)malloc(sizeof(int *) * info->content_length);
	if (!info->a || !info->b)
		exit(1);
	while (i < info->content_length)
	{
		info->a[i] = (int *)malloc(sizeof(int));
		info->b[i] = (int *)malloc(sizeof(int));
		if (!info->a[i] || !info->b[i])
			exit(1);
		*info->a[i] = ft_atoi(info->content[i]);
		i++;
	}
}
