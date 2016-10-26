/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 12:12:30 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/26 12:36:44 by plefebvr         ###   ########.fr       */
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

void				clearscreen(void)
{
	write(2, "\e[1;1H\e[2J", 12);
}
