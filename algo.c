/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 05:07:36 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/27 18:01:50 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			algo_ll_h(t_env *info)
{
	int			y;
	int			x;

	x = 0;
	while (x + info->piece_real_x <= info->map_size_x)
	{
		y = info->map_size_y;
		while (y >= 0)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			y--;
		}
		x++;
	}
	ft_printf("0 0\n");
}

static void			algo_lr_h(t_env *info)
{
	int			y;
	int			x;

	x = info->map_size_x;
	while (x >= 0)
	{
		y = info->map_size_y;
		while (y >= 0)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			y--;
		}
		x--;
	}
	ft_printf("0 0\n");
}

static void			algo_ul_h(t_env *info)
{
	int			y;
	int			x;

	x = 0;
	while (x + info->piece_real_x <= info->map_size_x)
	{
		y = 0;
		while (y + info->piece_real_y <= info->map_size_y)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			y++;
		}
		x++;
	}
	ft_printf("0 0\n");
}

static void			algo_ur_h(t_env *info)
{
	int			y;
	int			x;

	x = info->map_size_x;
	while (x >= 0)
	{
		y = 0;
		while (y + info->piece_real_y <= info->map_size_y)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			y++;
		}
		x--;
	}
	ft_printf("0 0\n");
}

void				choose_algo(t_env *info)
{
	info->free = 0;
	if (info->piece_info > 0)
	{
		if (info->direction_y == 1)
			info->direction_x == 1 ? algo_ll_h(info) : algo_lr_h(info);
		else if (info->direction_y == -1)
			info->direction_x == 1 ? algo_ul_h(info) : algo_ur_h(info);
	}
	else
		algo_v(info);
	info->step = 42;
}
