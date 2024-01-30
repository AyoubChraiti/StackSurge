/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:14 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/29 16:44:23 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_list *info)
{
	int	*tmp;
	int	i;

	if (info->count_b > 1 && info->content_length > 1)
	{
		i = info->content_length - 1;
		tmp = info->a[info->content_length - 1];
		while (i > 0)
		{
			info->a[i] = info->a[i - 1];
			i--;
		}
		info->a[0] = tmp;
		i = info->count_b - 1;
		tmp = info->b[info->count_b - 1];
		while (i > 0)
		{
			info->b[i] = info->b[i - 1];
			i--;
		}
		info->b[0] = tmp;
		write(1, "rrr\n", 4);
	}
}

void	check_args(char *s, t_list *info)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			print_exit(info);
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			flag = 1;
		i++;
	}
	if (!flag)
		print_exit(info);
}

void	exit1(t_list *info, int i)
{
	write(2, "Error\n", 6);
	while (i > 0)
	{
		free(info->a[i]);
		free(info->b[i]);
		i--;
	}
	free(info->a);
	free(info->b);
	free(info->bak_a);
	free(info->bak_b);
	exit(1);
}

void	malloced(t_list *info)
{
	int	i;

	i = 0;
	info->flag_overflow = 0;
	while (i < info->content_length)
	{
		info->a[i] = (int *)malloc(sizeof(int));
		info->b[i] = (int *)malloc(sizeof(int));
		info->bak_a[i] = info->a[i];
		info->bak_b[i] = info->b[i];
		if (!info->a[i] || !info->b[i])
			exit1(info, i);
		*info->a[i] = ft_atoi(info->content[i]);
		i++;
	}
}

void	initialize_t_list(char *s, t_list *info)
{
	int	i;

	i = 0;
	info->count_b = 0;
	info->cont = s;
	info->content = ft_split(s, ' ');
	i = 0;
	info->a = (int **)malloc(sizeof(int *) * info->content_length);
	info->bak_a = (int **)malloc(sizeof(int *) * info->content_length);
	if (!info->a || !info->bak_a)
		return (free(info->a), free(info->bak_a), exit(1));
	info->b = (int **)malloc(sizeof(int *) * info->content_length);
	info->bak_b = (int **)malloc(sizeof(int *) * info->content_length);
	if (!info->b || !info->bak_b)
		return (free(info->b), free(info->bak_b), exit(1));
	malloced(info);
	while (i < info->content_length)
	{
		if (ft_atoi(info->content[i]) > 2147483647
			|| ft_atoi(info->content[i]) < -2147483648)
			info->flag_overflow = 1;
		i++;
	}
	free_content(info);
}
