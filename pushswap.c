/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:02:49 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/20 12:07:44 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int is_sorted(t_list *stacks)
{
     int    i;

     i = 1;
    if (stacks->content_length <= 1)
        return 1;
    while (i < stacks->content_length)
    {
        if (stacks->a[i - 1] > stacks->a[i])
            return 0;
        i++;
    }
    return 1;
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

void	initialize_t_list(char *s, t_list *info)
{
	int	i;

	i = 0;
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
		tmp = ft_strjoin(s, " ");
		i++;
	}
	info.content_length = count_element(s);
	info.count_b = 0;
	info.cont = s;
	check_args(s);
	initialize_t_list(s, &info);
	parse_stack(&info);
	print_stacks(&info);
	push_swap(&info);
	print_stacks(&info);
}
