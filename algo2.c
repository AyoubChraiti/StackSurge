/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:51:46 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/28 14:46:18 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_(t_stack *s, t_list *stacks, int num)
{
	int	i;
	int	smallest_bigger;
	int	smallest;

	i = 0;
	smallest_bigger = INT_MAX;
	smallest = INT_MAX;
	while (i < stacks->content_length)
	{
		if (*stacks->a[i] > num && *stacks->a[i] < smallest_bigger)
		{
			smallest_bigger = *stacks->a[i];
			s->index_bigger = i;
		}
		if (*stacks->a[i] < smallest)
		{
			smallest = *stacks->a[i];
			s->index_smallest = i;
		}
		i++;
	}
}

int	find_smallest_bigger(t_list *stacks, int num)
{
	t_stack	s;
	int		i;

	s.index_bigger = -1;
	s.index_smallest = 0;
	i = 0;
	get_(&s, stacks, num);
	if (s.index_bigger != -1)
		return (s.index_bigger);
	else
		return (s.index_smallest);
}

t_match	find_cheapest_match(t_list *stacks)
{
	int		i;
	int		index_a;
	int		cost;
	t_match	cheapest;

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

int	is_sorted1(t_list *stacks)
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

void	push_swap(t_list *stacks)
{
	t_match	cheapest;

	if (is_sorted1(stacks))
		return (ft_free1(stacks));
	else if (stacks->content_length == 2 && *stacks->a[0] > *stacks->a[1])
		sa(stacks);
	else if (stacks->content_length == 3)
		sort_three_elements(stacks);
	else if (stacks->content_length > 3)
	{
		while (stacks->content_length > 3)
			pb(stacks);
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
	ft_free1(stacks);
}
