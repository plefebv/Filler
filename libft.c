/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 19:32:23 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 20:38:32 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
