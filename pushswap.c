/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:02:49 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/29 16:18:31 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	checkers(t_list *info, char *s)
{
	check_args(s, info);
	parse_stack(info);
}

void	algo(t_list *info)
{
	if (info->flag_overflow == 1)
	{
		ft_free1(info);
		write(1, "Error\n", 6);
		system("leaks push_swap");
		exit(1);
	}
	else
		push_swap(info);
}

int	main(int argc, char **argv)
{
	t_list	info;
	int		i;
	char	*s;
	char	*tmp;

	if (argc < 2)
		exit(1);
	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		s = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = ft_strjoin(s, " ");
		if (i != argc - 1 && argv[i] != s)
			free(s);
		i++;
	}
	free(tmp);
	info.content_length = count_element(s);
	initialize_t_list(s, &info);
	checkers(&info, s);
	if (s != argv[i - 1])
		free(s);
	algo(&info);
}
