/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:13:43 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/02 12:32:45 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void				identify_players(t_env *info, char *str)
{
	info->free = 0;
	if (ft_strinstr(str, "$$$ exec p1"))
	{
		info->ltr_player = 'O';
		info->ltr_ennemy = 'X';
		ft_strdel(&str);
	}
	else if (ft_strinstr(str, "$$$ exec p2"))
	{
		info->ltr_player = 'X';
		info->ltr_ennemy = 'O';
		ft_strdel(&str);
	}
	info->step = 1;
}

static int				checkline(char *str, int p)
{
	int		i;
	int		nb;

	nb = 0;
	i = (p > 0 ? 6 : 8);
	if (ft_strinstr(str, p > 0 ? "Piece " : "Plateau "))
	{
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (i != p > 0 ? 6 : 8)
			nb = 1;
		if (str[++i] && str[i] == ' ')
			i++;
		if (str[i] && ft_isdigit(str[i]) && nb == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

static void				init_game(t_env *info, char *str)
{
	if (info->step == 0 && ft_strinstr(str, "$$$ exec"))
		identify_players(info, str);
	if (info->step == 1 && checkline(str, 0))
		grab_map_size(info, str);
	if (info->step == 2)
		grab_map(info, str);
	if (info->step == 3 && checkline(str, 1))
	{
		grab_piece_size(info, str);
		grab_piece(info, str);
	}
}

static void				work_filler(t_env *info, char *str)
{
	t_pp			pp;

	init_game(info, str);
	info->step == 5 ? take_position(info, &pp, -1, -1) : 0;
	info->step == 6 ? take_parts(info) : 0;
	info->step == 7 ? take_direction(info, &pp) : 0;
	info->step == 8 ? choose_algo(info) : 0;
	info->step == 42 ? free_info(info) : 0;
	(info->free == 1) ? ft_strdel(&str) : 0;
}

int						main(void)
{
	char			*str;
	t_env			info;

	str = NULL;
	info.step = 0;
	while (get_next_line(0, &str) > 0)
		work_filler(&info, str);
	return (0);
}
