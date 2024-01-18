/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:51:46 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/18 12:14:28 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void push_swap(t_list *stacks)
{
	if (stacks->content_length == 1)
		return ;
	else if (stacks->content_length == 2)
		sort_two_elements(stacks);
	else if (stacks->content_length == 3)
		sort_three_elements(stacks);
	else if (stacks->content_length > 3)
	{
		printf("chill\n");
	}
}

