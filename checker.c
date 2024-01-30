/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:11:04 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/29 16:43:38 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	process_instruction(char *instruction, t_list *x)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(x);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(x);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(x);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(x);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(x);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(x);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(x);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(x);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(x);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(x);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(x);
	else
		return (0);
	return (1);
}

void	read_instructions(t_list *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!process_instruction(line, stacks))
		{
			write(2, "Error\n", 6);
			free(line);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

void	check_if_ok(t_list *stacks)
{
	if (is_sorted(stacks) && is_empty(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	checks(t_list *x, char *s)
{
	check_args1(s, x);
	parse_stack(x);
	algo(x);
	read_instructions(x);
	check_if_ok(x);
}

int	main(int argc, char **argv)
{
	char	*tmp;
	char	*s;
	int		i;
	t_list	x;

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
	x.content_length = count_element(s);
	initialize_t_list(s, &x);
	checks(&x, s);
	if (s != argv[i - 1])
		free(s);
	ft_free1(&x);
}
