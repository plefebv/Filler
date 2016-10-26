/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:01:24 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/26 11:38:56 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				take_parts(t_env *info)
{
	int		y;
	int		x;
	int		part;

	part = 0;
	y = 0;
	malloc_parts(info);
	while (y < info->piece_size_y)
	{
		x = 0;
		while (x < info->piece_size_x)
		{
			if (info->piece[y][x] == '*')
			{
				info->parts[part][0] = y;
				info->parts[part][1] = x;
				part++;
			}
			x++;
		}
		y++;
	}
	grab_real_size_piece(info, 0, 0, 0);
	info->step = 7;
}

int					test_piece(t_env *info, int add_y, int add_x)
{
	int		part;
	int		x;
	int		y;
	int		find;

	part = 0;
	find = 0;
	while (part < info->nbr_parts)
	{
		y = info->parts[part][0] + add_y;
		x = info->parts[part][1] + add_x;
		if (y > info->map_size_y - 1 || x > info->map_size_x - 1)
			return (0);
		if (info->map[y][x] == info->ltr_player)
			find++;
		if (find > 1 || info->map[y][x] == info->ltr_ennemy)
			return (0);
		part++;
	}
	if (find == 1)
		return (1);
	return (0);
}
