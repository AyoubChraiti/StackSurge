/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:17:33 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/30 14:56:51 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+')
			&& (s[i + 1] == '+' || s[i + 1] == '-'))
			return (0);
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) && (s[i + 1] == '-' || s[i + 1] == '+'))
			return (0);
		if ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_list *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->content_length)
	{
		j = 0;
		while (j < i)
		{
			if (*info->a[i] == *info->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free1(t_list *info)
{
	int	i;
 
	i = 0;
	while (i < info->content_length)
	{
		free(info->bak_a[i]);
		free(info->bak_b[i]);
		i++;
	}
	free(info->a);
	free(info->b);
	free(info->bak_a);
	free(info->bak_b);
}

void	parse_stack(t_list *info)
{
	if (!check_dup(info) || !check_sign(info->cont))
		print_exit(info);
}

void	print_exit(t_list *info)
{
	write(2, "Error\n", 6);
	ft_free1(info);
	exit(1);
}
