/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 14:20:52 by plefebvr          #+#    #+#             */
/*   Updated: 2016/09/17 14:22:59 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtolower(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		i++;
	}
	return (s);
}
