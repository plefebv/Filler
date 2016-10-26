/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:45:22 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/26 12:48:30 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			tgp2(t_env *info, t_pp *pp)
{
	if (pp->emin_y < info->map_size_y / 2)
	{
		if (pp->emin_x < info->map_size_x / 2)
			pp->e_global = 0;
		else
			pp->e_global = 1;
	}
	else
	{
		if (pp->emin_x < info->map_size_x / 2)
			pp->e_global = 2;
		else
			pp->e_global = 3;
	}
}

void				take_global_position(t_env *info, t_pp *pp)
{
	if (pp->pmin_y < info->map_size_y / 2)
	{
		if (pp->pmin_x < info->map_size_x / 2)
			pp->p_global = 0;
		else
			pp->p_global = 1;
	}
	else
	{
		if (pp->pmin_x < info->map_size_x / 2)
			pp->p_global = 2;
		else
			pp->p_global = 3;
	}
	tgp2(info, pp);
}

static void			init_pp(t_env *info, t_pp *pp)
{
	pp->emax_y = 0;
	pp->emin_y = info->map_size_y;
	pp->emax_x = 0;
	pp->emin_x = info->map_size_x;
	pp->pmax_y = 0;
	pp->pmin_y = info->map_size_y;
	pp->pmax_x = 0;
	pp->pmin_x = info->map_size_x;
	pp->p_global = -1;
	pp->e_global = -1;
}

void				take_position(t_env *info, t_pp *pp, int i, int x)
{
	init_pp(info, pp);
	while (++i < info->map_size_y)
	{
		x = -1;
		while (info->map[i][++x])
		{
			if (info->map[i][x] == info->ltr_player)
			{
				i > pp->pmax_y ? pp->pmax_y = i : 0;
				i < pp->pmin_y ? pp->pmin_y = i : 0;
				x > pp->pmax_x ? pp->pmax_x = x : 0;
				x < pp->pmin_x ? pp->pmin_x = x : 0;
			}
			if (info->map[i][x] == info->ltr_ennemy)
			{
				i > pp->emax_y ? pp->emax_y = i : 0;
				i < pp->emin_y ? pp->emin_y = i : 0;
				x > pp->emax_x ? pp->emax_x = x : 0;
				x < pp->emin_x ? pp->emin_x = x : 0;
			}
		}
	}
	info->step = 6;
}

int			ft_strinstr(const char *str1, const char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		j = 0;
		while (str1[i] == str2[j])
		{
			j++;
			i++;
		}
		if (!str2[j])
			return (1);
		i++;
	}
	return (0);
}
