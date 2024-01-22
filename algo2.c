/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:51:46 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/22 16:18:16 by achraiti         ###   ########.fr       */
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
	if (index_a <= stacks->content_length / 2 || index_a == stacks->content_length / 2)
		cost += index_a;
	else
		cost += stacks->content_length - index_a;
	return cost;
}

int	find_smallest_bigger(t_list *stacks, int num)
{
	int smallest_bigger;
	int smallest;
	int index_bigger;
	int index_smallest;
	int i;

	smallest_bigger = INT_MAX;
	smallest = INT_MAX;
	index_bigger = -1;
	index_smallest = 0;
	i = 0;
	while (i < stacks->content_length)
	{
		if (*stacks->a[i] > num && *stacks->a[i] < smallest_bigger)
		{
			smallest_bigger = *stacks->a[i];
			index_bigger = i;
		}
		if (*stacks->a[i] < smallest)
		{
			smallest = *stacks->a[i];
			index_smallest = i;
		}
		i++;
	}
	return (index_bigger != -1 ? index_bigger : index_smallest);
}

t_match	find_cheapest_match(t_list *stacks)
{
	int		i;
	int		index_a;
	int		cost;
	t_match cheapest;

	i = 0;
	cheapest.cost = INT_MAX;
	while (i < stacks->count_b)
	{
		index_a = find_smallest_bigger(stacks, *stacks->b[i]);
		cost = calculate_cost(stacks, i, index_a);
		if (cost < cheapest.cost)
		{
			cheapest.index_b = i;
			cheapest.index_a = index_a;
			cheapest.cost = cost;
		}
		i++;
	}
	return (cheapest);
}

void	push_swap(t_list *stacks)
{
	t_match cheapest;

	if (stacks->content_length == 1)
		return;
	else if (stacks->content_length == 2)
		sort_two_elements(stacks);
	else if (stacks->content_length == 3)
		sort_three_elements(stacks);
	else if (stacks->content_length > 3)
	{
		while (stacks->content_length > 3)
		{
			pb(stacks);
		}
		sort_three_elements(stacks);
		while (stacks->count_b > 0)
		{
			cheapest = find_cheapest_match(stacks);
			rotate_until_a(stacks, cheapest.index_a);
			rotate_until_b(stacks, cheapest.index_b);
			pa(stacks);
		}
		rotate_smallest_to_top(stacks);
	}
}