/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:18:32 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/25 13:45:15 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	calculate_cost(t_list *stacks, int index_b, int index_a)
{
	int	cost;

	cost = 0;
	if (index_b <= stacks->count_b / 2 || index_b == stacks->count_b / 2)
		cost += index_b;
	else
		cost += stacks->count_b - index_b;
	if (index_a <= stacks->content_length / 2
		|| index_a == stacks->content_length / 2)
		cost += index_a;
	else
		cost += stacks->content_length - index_a;
	return (cost);
}

void	rotate_until_a(t_list *stacks, int index)
{
	if (index <= stacks->content_length / 2)
	{
		while (--index >= 0)
			ra(stacks);
	}
	else
	{
		index = stacks->content_length - index;
		while (--index >= 0)
			rra(stacks);
	}
}

void	rotate_smallest_to_top(t_list *stacks)
{
	int	smallest;
	int	index_smallest;
	int	i;

	smallest = INT_MAX;
	index_smallest = -1;
	i = 0;
	while (i < stacks->content_length)
	{
		if (*stacks->a[i] < smallest)
		{
			smallest = *stacks->a[i];
			index_smallest = i;
		}
		i++;
	}
	rotate_until_a(stacks, index_smallest);
}

void	rotate_until_b(t_list *stacks, int index)
{
	if (index <= stacks->count_b / 2)
	{
		while (--index >= 0)
			rb(stacks);
	}
	else
	{
		index = stacks->count_b - index;
		while (--index >= 0)
			rrb(stacks);
	}
}
