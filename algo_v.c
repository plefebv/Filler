/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 12:23:37 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/26 12:25:34 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			algo_ll_v(t_env *info)
{
	int			y;
	int			x;

	y = info->map_size_y;
	while (y >= 0)
	{
		x = 0;
		while (x + info->piece_real_x <= info->map_size_x)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			x++;
		}
		y--;
	}
	ft_printf("0 0\n");
}

static void			algo_lr_v(t_env *info)
{
	int		y;
	int		x;

	y = info->map_size_y;
	while (y >= 0)
	{
		x = info->map_size_x;
		while (x >= 0)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			x--;
		}
		y--;
	}
	ft_printf("0 0\n");
}

static void			algo_ul_v(t_env *info)
{
	int		y;
	int		x;

	y = 0;
	while (y + info->piece_real_y <= info->map_size_y)
	{
		x = 0;
		while (x + info->piece_real_x <= info->map_size_x)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	ft_printf("0 0\n");
}

static void			algo_ur_v(t_env *info)
{
	int		y;
	int		x;

	y = 0;
	while (y + info->piece_real_y <= info->map_size_y)
	{
		x = info->map_size_x;
		while (x >= 0)
		{
			if ((test_piece(info, y, x)))
			{
				ft_printf("%d %d\n", y, x);
				return ;
			}
			x--;
		}
		y++;
	}
	ft_printf("0 0\n");
}

void				algo_v(t_env *info)
{
	if (info->direction_y == 1)
		info->direction_x == 1 ? algo_ll_v(info) : algo_lr_v(info);
	else if (info->direction_y == -1)
		info->direction_x == 1 ? algo_ul_v(info) : algo_ur_v(info);
}
