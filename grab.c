/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:27:10 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/31 14:13:56 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					grab_piece_size(t_env *info, char *str)
{
	char		**tab;
	int			p;

	p = 0;
	info->free = 0;
	info->step = 4;
	tab = NULL;
	tab = ft_strsplit(str, ' ', &p);
	if (p != 3)
		return ;
	ft_memdel((void **)&tab[0]);
	info->piece_size_y = ft_atoi(tab[1]);
	ft_memdel((void **)&tab[1]);
	info->piece_size_x = ft_atoi(tab[2]);
	ft_memdel((void **)&tab[2]);
	free(*tab);
	free(tab);
	ft_strdel((char **)&str);
}

void					grab_map_size(t_env *info, char *str)
{
	char		**tab;
	int			p;

	p = 0;
	info->free = 0;
	tab = NULL;
	tab = ft_strsplit(str, ' ', &p);
	if (p != 3)
		return ;
	ft_memdel((void **)&tab[0]);
	info->map_size_y = ft_atoi(tab[1]);
	ft_memdel((void **)&tab[1]);
	info->map_size_x = ft_atoi(tab[2]);
	ft_memdel((void **)&tab[2]);
	free(*tab);
	free(tab);
	info->first = 0;
	info->step = 2;
}

void					grab_real_size_piece(t_env *info, int min_y, \
						int max_y, int min_x)
{
	int		max_x;
	int		i;

	max_x = 0;
	i = 0;
	min_y = info->piece_size_y;
	min_x = info->piece_size_x;
	while (i < info->nbr_parts)
	{
		if (info->parts[i][0] > max_y)
			max_y = info->parts[i][0];
		if (info->parts[i][1] > max_x)
			max_x = info->parts[i][1];
		if (info->parts[i][0] < min_y)
			min_y = info->parts[i][0];
		if (info->parts[i][1] < min_x)
			min_x = info->parts[i][1];
		i++;
	}
	info->piece_real_y = max_y - min_y + 1;
	info->piece_real_x = max_x - min_x + 1;
}

void					grab_piece(t_env *info, char *str)
{
	int		x;
	int		y;

	info->free = 0;
	x = 0;
	y = 0;
	info->nbr_parts = 0;
	info->piece = malloc_map(info->piece_size_y, info->piece_size_x);
	while (y < info->piece_size_y)
	{
		x = 0;
		get_next_line(0, &str);
		while (x < info->piece_size_x)
		{
			info->piece[y][x] = str[x];
			info->piece[y][x] == '*' ? info->nbr_parts++ : 0;
			x++;
		}
		ft_memdel((void **)&str);
		y++;
	}
	info->step = 5;
}

void					grab_map(t_env *info, char *str)
{
	int		x;
	int		y;
	int		i;

	y = -1;
	x = 0;
	info->free = 0;
	info->step = 3;
	info->map = malloc_map(info->map_size_y, info->map_size_x);
	ft_strdel(&str);
	get_next_line(0, &str);
	ft_strdel(&str);
	while (++y < info->map_size_y)
	{
		i = 0;
		x = 0;
		get_next_line(0, &str);
		while (ft_isdigit(str[i]) || str[i] == ' ')
			i++;
		while (x < info->map_size_x)
			info->map[y][x++] = str[i++];
		ft_strdel(&str);
	}
}
