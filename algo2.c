/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:51:46 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/20 17:33:55 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_index(int **array, int length, int *element)
{
    int i = 0;

    while (i < length)
    {
        if (*array[i] == *element)
            return i;
        i++;
    }
    return -1;
}

int calculate_moves(t_list *stacks, int *element)
{
    int moves_to_a;
    int moves_to_b;
    int index_a;
    int index_b;

    index_a = find_index(stacks->a, stacks->content_length, element);
    index_b = find_index(stacks->b, stacks->count_b, element);
    moves_to_a = index_a + 1;
    moves_to_b = index_b + 1;
    if (index_a > stacks->content_length / 2)
        moves_to_a = stacks->content_length - index_a;
    if (index_b > stacks->count_b / 2)
        moves_to_b = stacks->count_b - index_b;
    return (moves_to_b + moves_to_a);
}

int find_best_match(t_list *stacks)
{
    int i;
    int min_moves;
    int moves;

    min_moves = INT_MAX;
    i = 0;
    while (i < stacks->count_b)
    {
        moves = calculate_moves(stacks, stacks->b[i]);
        if (moves < min_moves)
            min_moves = moves;
        i++;
    }
    stacks->index_b = i;
    return (min_moves);
}

void rotate_a_to_match(t_list *stacks, int match_element)
{
    int index_a = find_index(stacks->a, stacks->content_length, &match_element);

    while (index_a != 0)
    {
        if (index_a <= stacks->content_length / 2)
            ra(stacks);
        else
            rra(stacks);
        index_a = find_index(stacks->a, stacks->content_length, &match_element);
    }
}

void push_best_match_to_a(t_list *stacks)
{
    int best_match_b = *stacks->b[stacks->index_b];
    rotate_a_to_match(stacks, best_match_b);
    pa(stacks);
}


void push_swap(t_list *stacks)
{
    int min_moves;
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
            min_moves = find_best_match(stacks);
            push_best_match_to_a(stacks);
        }
    }
}
