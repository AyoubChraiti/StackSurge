/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:11:04 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/22 20:24:38 by achraiti         ###   ########.fr       */
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

int process_instruction(char *instruction, t_list *x)
{
    if (ft_strncmp(instruction, "sa", 2) == 0)
        sa(x);
    else if (ft_strncmp(instruction, "sb", 2) == 0)
        sb(x);
    else if (ft_strncmp(instruction, "ss", 2) == 0)
        ss(x);
    else if (ft_strncmp(instruction, "pa", 2) == 0)
        pa(x);
    else if (ft_strncmp(instruction, "pb", 2) == 0)
        pb(x);
    else if (ft_strncmp(instruction, "ra", 2) == 0)
        ra(x);
    else if (ft_strncmp(instruction, "rb", 2) == 0)
        rb(x);
    else if (ft_strncmp(instruction, "rr", 2) == 0)
        rr(x);
    else if (ft_strncmp(instruction, "rra", 3) == 0)
        rra(x);
    else if (ft_strncmp(instruction, "rrb", 3) == 0)
        rrb(x);
    else if (ft_strncmp(instruction, "rrr", 3) == 0)
        rrr(x);
    else
        return (0);
    return (1);
}

int is_empty(t_list *stacks)
{
    if (stacks->count_b == 0)
        return (1);
    return (0);
}

int is_sorted(t_list *stacks)
{
    int i;

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

int main(int argc, char **argv)
{
    char    *line;
    char    *tmp;
    char    *s;
    int     i;
    t_list  x;

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
	x.cont = s;
    x.content_length = count_element(s);
	x.count_b = 0;
    check_args(s);
    initialize_t_list(s, &x);
    parse_stack(&x);
    while (((line = get_next_line(0)) != NULL) && line[0] != '\0')
    {
        if (!process_instruction(line, &x))
        {
            ft_printf("Error\n");
            free(line);
            return (1);
        }
        free(line);
    }
    if (is_sorted(&x) && is_empty(&x))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    return (0);
}
