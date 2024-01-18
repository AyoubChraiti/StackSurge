/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:17:33 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/11 14:09:37 by achraiti         ###   ########.fr       */
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
		if (ft_isdigit(s[i]) && s[i + 1] == '-')
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

void	parse_stack(t_list *info)
{
	if (!check_dup(info) || !check_sign(info->cont))
		print_exit();
}

void	print_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}
