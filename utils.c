/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:45:22 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/25 17:24:39 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				ft_putstr_color_fd(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'X')
			ft_putstr_fd("\033[96mX\033[0m", fd);
		else if (str[i] == 'x')
			ft_putstr_fd("\033[96mx\033[0m", fd);
		else if (str[i] == 'O')
			ft_putstr_fd("\033[95mO\033[0m", fd);
		else if (str[i] == 'o')
			ft_putstr_fd("\033[95mo\033[0m", fd);
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

static int			get_x_position(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int			get_x_l_position(char *str, char c, int i)
{
	
	while (--i >= 0)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

static void			put_l_position(t_pp *pp, int y, int x, int p)
{
	if (!p)
	{
		pp->pl_x = x;
		pp->pl_y = y;
	}
	else
	{
		pp->el_x = x;
		pp->el_y = y;
	}
}

static void			put_f_position(t_pp *pp, int y, int x, int p)
{
	if (!p)
	{
		pp->pf_x = x;
		pp->pf_y = y;
	}
	else
	{
		pp->ef_x = x;
		pp->ef_y = y;
	}
}

static void			take_global_position(t_env *info, t_pp *pp)
{
	if (pp->pf_y < info->map_size_y / 2)
	{
		if (pp->pf_x <info->map_size_x / 2)
			pp->p_global = 0;
		else
			pp->p_global = 1;
	}
	else
	{
		if (pp->pf_x < info->map_size_x / 2)
			pp->p_global = 2;
		else
			pp->p_global = 3;
	}
	if (pp->ef_y < info->map_size_y / 2)
	{
		if (pp->ef_x < info->map_size_x / 2)
			pp->e_global = 0;
		else
			pp->e_global = 1;
	}
	else
	{
		if (pp->ef_x < info->map_size_x / 2)
			pp->e_global = 2;
		else
			pp->e_global = 3;
	}
}


void				take_direction(t_env *info, t_pp *pp)
{
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
		if (pp->p_global == 0)
		{
			if (pp->e_global == 1)
			{
				info->direction_x = -1;
				info->direction_y = info->piece_info >= 0 ?  1 : -1;
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
		else if (pp->p_global == 1)
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
		else if (pp->p_global == 2)
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
		else if (pp->p_global == 3)
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

	info->step = 8;
}

static void			init_pp(t_env *info, t_pp *pp)
{
	pp->pf_x = -1;
	pp->ef_x = -1;
	pp->pl_x = -1;
	pp->el_x = -1;
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

void				take_position(t_env *info, t_pp *pp)
{
	int			i;
	int			tmp;
	int			x;

	x = 0;
	i = 0;
	tmp = -1;
	init_pp(info, pp);
	while (i < info->map_size_y)
	{
		x = 0;
		while (info->map[i][x])
		{
			if (info->map[i][x] == info->ltr_player)
			{
				if (i > pp->pmax_y)
					pp->pmax_y = i;
				if (i < pp->pmin_y)
					pp->pmin_y = i;
				if (x > pp->pmax_x)
					pp->pmax_x = x;
				if (x < pp->pmin_x)
					pp->pmin_x = x;
			}
			if (info->map[i][x] == info->ltr_ennemy)
			{
				if (i > pp->emax_y)
					pp->emax_y = i;
				if (i < pp->emin_y)
					pp->emin_y = i;
				if (x > pp->emax_x)
					pp->emax_x = x;
				if (x < pp->emin_x)
					pp->emin_x = x;
			}
			x++;
		}
		if (pp->pf_x == -1)
		{
			tmp = get_x_position(info->map[i], info->ltr_player);
			tmp != -1 ? put_f_position(pp, i, tmp, 0) : 0;
		}
		if (pp->ef_x == -1)
		{
			tmp = get_x_position(info->map[i], info->ltr_ennemy);
			tmp != -1 ? put_f_position(pp, i, tmp, 1) : 0;
		}
		i++;
	}
	i = info->map_size_y;
	while (--i >= 0)
	{
		if (pp->pl_x == -1)
		{
			tmp = get_x_l_position(info->map[i], info->ltr_player, info->map_size_x);
			tmp != -1 ? put_l_position(pp, i, tmp, 0) : 0;
		}
		if (pp->el_x == -1)
		{
			tmp = get_x_l_position(info->map[i], info->ltr_ennemy, info->map_size_x);
			tmp != -1 ? put_l_position(pp, i, tmp, 1) : 0;
		}
	}
	info->step = 6;
}
