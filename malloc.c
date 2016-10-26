/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:43:43 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/26 11:36:10 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				malloc_parts(t_env *info)
{
	int			i;
	int			**tmp;

	i = 0;
	tmp = (int **)ft_memalloc(sizeof(int *) * (info->nbr_parts + 1000));
	while (i < info->nbr_parts)
	{
		tmp[i] = (int *)ft_memalloc(sizeof(int) * 1000);
		i++;
	}
	info->parts = tmp;
}

static void			freetabtabint(int **tab, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab[i]);
	ft_memdel((void **)&tab);
}

static void			freetabtabchar(char **tab, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
		ft_memdel((void **)&tab[i++]);
	ft_memdel((void **)&tab[i]);
	ft_memdel((void **)&tab);
}

void				free_info(t_env *info)
{
	freetabtabchar(info->map, info->map_size_y);
	freetabtabchar(info->piece, info->piece_size_y);
	freetabtabint(info->parts, info->nbr_parts);
	info->piece_info = 0;
	info->piece_size_y = 0;
	info->piece_size_x = 0;
	info->nbr_parts = 0;
	info->step = 2;
}

char				**malloc_map(int y, int x)
{
	char		**map;
	int			i;

	i = 0;
	map = NULL;
	if ((map = (char **)ft_memalloc(sizeof(char *) * (y + 1))))
	{
		while (i < y)
			map[i++] = ft_strnew(x);
		return (map);
	}
	return (NULL);
}
