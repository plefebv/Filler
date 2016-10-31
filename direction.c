/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 11:46:45 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/27 18:00:20 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			p0(t_env *info, t_pp *pp)
{
	if (pp->p_global == 0)
	{
		if (pp->e_global == 1)
		{
			info->direction_x = -1;
			info->direction_y = info->piece_info >= 0 ? 1 : -1;
		}
		else if (pp->e_global == 2)
		{
			info->direction_x = info->piece_info >= 0 ? 1 : -1;
			info->direction_y = -1;
		}
		else if (pp->e_global == 3)
		{
			info->direction_x = info->piece_info >= 0 ? -1 : 1;
			info->direction_y = -1;
		}
	}
}

static void			p1(t_env *info, t_pp *pp)
{
	if (pp->p_global == 1)
	{
		if (pp->e_global == 0)
		{
			info->direction_x = 1;
			info->direction_y = info->piece_info >= 0 ? 1 : -1;
		}
		if (pp->e_global == 2)
		{
			info->direction_x = info->piece_info >= 0 ? 1 : -1;
			info->direction_y = 1;
		}
		if (pp->e_global == 3)
		{
			info->direction_x = info->piece_info >= 0 ? -1 : 1;
			info->direction_y = 1;
		}
	}
}

static void			p2(t_env *info, t_pp *pp)
{
	if (pp->p_global == 2)
	{
		if (pp->e_global == 0)
		{
			info->direction_x = info->piece_info >= 0 ? 1 : -1;
			info->direction_y = -1;
		}
		if (pp->e_global == 1)
		{
			info->direction_x = info->piece_info >= 0 ? -1 : 1;
			info->direction_y = -1;
		}
		if (pp->e_global == 3)
		{
			info->direction_x = info->piece_info >= 0 ? -1 : 1;
			info->direction_y = -1;
		}
	}
}

static void			p3(t_env *info, t_pp *pp)
{
	if (pp->p_global == 3)
	{
		if (pp->e_global == 0)
		{
			info->direction_x = info->piece_info >= 0 ? 1 : -1;
			info->direction_y = -1;
		}
		if (pp->e_global == 1)
		{
			info->direction_x = info->piece_info >= 0 ? -1 : 1;
			info->direction_y = -1;
		}
		if (pp->e_global == 2)
		{
			info->direction_x = 1;
			if (pp->emin_y < pp->pmin_y)
				info->direction_y = -1;
			else
				info->direction_y = info->piece_info >= 0 ? -1 : 1;
		}
	}
}

void				take_direction(t_env *info, t_pp *pp)
{
	info->free = 0;
	take_global_position(info, pp);
	info->piece_real_y < info->piece_real_x ? info->piece_info = 1 : 0;
	info->piece_real_y > info->piece_real_x ? info->piece_info = -1 : 0;
	info->piece_real_y == info->piece_real_x ? info->piece_info = 0 : 0;
	if (pp->p_global == pp->e_global)
	{
		info->direction_x = pp->pmin_x < pp->emin_x ? -1 : 1;
		info->direction_y = pp->pmin_y < pp->emin_y ? 1 : -1;
	}
	else
	{
		p0(info, pp);
		p1(info, pp);
		p2(info, pp);
		p3(info, pp);
	}
	info->step = 8;
}
