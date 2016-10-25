/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:13:43 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/25 17:18:13 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			init_game(t_env *info, char *str)
{
		if (info->step == 0 && ft_strinstr(str, "$$$ exec"))
			identify_players(info, str);
		if (info->step == 1 && ft_strinstr(str, "Plateau"))
			grab_map_size(info, str);
		if (info->step == 2)
			grab_map(info, str);
		if (info->step == 3 && ft_strinstr(str, "Piece"))
		{
			grab_piece_size(info, str);
			grab_piece(info, str);
		}
}

static void			work_filler(t_env *info, char *str)
{
	t_pp			pp;

	init_game(info, str);
	info->step == 5 ? take_position(info, &pp) : 0;
	info->step == 6 ? take_parts(info) : 0;
	info->step == 7 ? take_direction(info, &pp) : 0;
	info->step == 8 ? choose_algo(info) : 0;
	info->step == 42 ? free_info(info) : 0;
}

int					main(void)
{
	char 			*str;
	t_env			info;

	str = NULL;
	info.step = 0;
	while (get_next_line(0, &str))
	{
		work_filler(&info, str);
		free(str);
	}
	return (0);
}
