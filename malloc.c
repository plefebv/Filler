/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:43:43 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/30 13:57:57 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					**malloc_parts(t_env *info)
{
	int			i;
	int			**tmp;

	i = 0;
	tmp = (int **)ft_memalloc(sizeof(int *) * (info->nbr_parts));
	while (i < info->nbr_parts)
	{
		tmp[i] = (int *)ft_memalloc(sizeof(int) * 2);
		i++;
	}
	return (tmp);
}

static void			freetabtabint(int **tab, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void			freetabtabchar(char **tab, int nbr)
{
	int		i;

	i = 0;
	while (i <= nbr)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(*tab);
	free(tab);
}

void				free_info(t_env *info)
{
	freetabtabint(info->parts, info->nbr_parts);
	freetabtabchar(info->map, info->map_size_y);
	freetabtabchar(info->piece, info->piece_size_y);
	info->piece_info = 0;
	info->piece_size_y = 0;
	info->piece_size_x = 0;
	info->nbr_parts = 0;
	info->map = NULL;
	info->piece = NULL;
	info->step = 2;
}

char				**malloc_map(int y, int x)
{
	char		**map;
	int			i;

	i = 0;
	map = NULL;
	if ((map = (char **)ft_memalloc(sizeof(char *) * (y) + 1)))
	{
		while (i <= y)
		{
			map[i++] = ft_strnew(x);
		}
		return (map);
	}
	return (NULL);
}
