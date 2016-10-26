/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 19:34:36 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/26 12:39:48 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"

# define MAP(y, x) 		info->map[y][x]
# define PIECE(y, x)	info->piece[y][x]

typedef struct			s_env
{
	int					step;

	int					ltr_player;
	int					ltr_ennemy;

	char				**map;
	int					map_size_y;
	int					map_size_x;

	char				**piece;
	char				**pce;
	int					piece_size_y;
	int					piece_size_x;
	int					piece_real_y;
	int					piece_real_x;
	int					piece_info;

	int					**parts;
	int					nbr_parts;

	char				direction_x;
	char				direction_y;
}						t_env;

typedef struct			s_pp
{
	int					emax_y;
	int					emin_y;
	int					emax_x;
	int					emin_x;

	int					pmax_y;
	int					pmin_y;
	int					pmax_x;
	int					pmin_x;

	int					p_global;
	int					e_global;
}						t_pp;

/*
** Add function to Libft
*/

int						ft_strinstr(const char *str1, const char *str2);

/*
** Grab Functions
*/

void					grab_piece_size(t_env *info, char *str);
void					grab_piece(t_env *info, char *str);
void					grab_map_size(t_env *info, char *str);
void					grab_map(t_env *info, char *str);
void					grab_real_size_piece(t_env *info, int min_y, \
						int max_y, int min_x);
/*
** Memory Functions
*/

char					**malloc_map(int y, int x);
void					malloc_parts(t_env *info);
void					free_info(t_env *info);

/*
** Utils Functions
*/

void					ft_putstr_color_fd(char *str, int fd);
void					take_position(t_env *info, t_pp *pp, int i, int x);
void					take_direction(t_env *info, t_pp *pp);
void					take_global_position(t_env *info, t_pp *pp);
void					clearscreen(void);

/*
** Parts Functions
*/

void					take_parts(t_env *info);
int						test_piece(t_env *info, int add_y, int add_x);

/*
** Algo Function
*/

void					choose_algo(t_env *info);
void					algo_v(t_env *info);

#endif
