/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:50:42 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/27 00:00:58 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_empty(t_list *stacks)
{
	if (stacks->count_b == 0)
		return (1);
	return (0);
}

int	is_sorted(t_list *stacks)
{
	int	i;

	i = 1;
	if (stacks->content_length == 1)
		return (1);
	while (i < stacks->content_length)
	{
		if (*stacks->a[i - 1] > *stacks->a[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_overflow(t_list *info)
{
	char	*str;
	int		i;

	i = 0;
	while (i < info->content_length)
	{
		str = ft_itoa(*info->a[i]);
		if (ft_strlen((str)) > 12)
			print_exit(info);
		free(str);
		i++;
	}
}

int	count_element(char *s)
{
	int	i;
	int	rs;

	i = 0;
	rs = 0;
	while (s[i])
	{
		if (s[i] == ' ' && s[i])
			i++;
		if (s[i] != ' ' && s[i])
		{
			rs++;
			while (s[i] != ' ' && s[i] != '\0')
				i++;
		}
	}
	return (rs);
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
