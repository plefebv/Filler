/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:43:43 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/19 16:52:47 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				malloc_parts(t_env *info)
{
	int			i;
	int			**tmp;
	i = 0;

	//ft_putendl_fd("malloc parts 0", 2);
	//ft_putstr_fd("nbr_parts = ", 2);
	//ft_putnbr_fd(info->nbr_parts, 2);
	//ft_putendl_fd("", 2);
	tmp = (int **)ft_memalloc(sizeof(int *) * (info->nbr_parts + 1000));
	//ft_putendl_fd("malloc parts 1", 2);
	while (i < info->nbr_parts)
	{
		//ft_putnbr_fd(i, 2);
		tmp[i] = (int *)ft_memalloc(sizeof(int) * 1000);
		i++;
		//ft_putnbr_fd(i, 2);
	}
	//ft_putnbr_fd(errno, 2);
	//ft_putendl_fd("junior", 2);
	info->parts = tmp;
	//ft_putendl_fd("junior1", 2);
	//ft_putendl_fd("malloc final", 2);
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
	//ft_memdel((void **)&tab[i]);
	ft_memdel((void **)&tab);
}


static void			freetabtabchar(char **tab, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
		ft_memdel((void **)&tab[i++]);
	//free(*tab);
	//ft_memdel((void **)&tab);
}

void				free_info(t_env *info)
{
	//ft_putendl_fd("prouta", 2);
	freetabtabchar(info->map, info->map_size_y);
	//ft_putendl_fd("prouta", 2);
	freetabtabchar(info->piece, info->piece_size_y);
	//ft_putendl_fd("prouta", 2);
	freetabtabint(info->parts, info->nbr_parts);
	//ft_putendl_fd("prouta", 2);
	//info->parts = NULL;
	//info->piece = NULL;
	//info->map = NULL;
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
