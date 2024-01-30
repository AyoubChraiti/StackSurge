/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:41:56 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/29 16:44:05 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	algo(t_list *info)
{
	if (info->flag_overflow == 1)
	{
		ft_free1(info);
		write(1, "Error\n", 6);
		exit(1);
	}
}
