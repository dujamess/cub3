/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonnus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:17:46 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 22:16:32 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

int	ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	the_biggest_line(t_info *info)
{
	int	index;
	int	tmp;
	int	len;
	int	i;

	i = 0;
	tmp = ft_strlen(info->maps[i]);
	while (info->maps[++i])
	{
		len = ft_strlen(info->maps[i]);
		if (len > tmp)
		{
			index = i;
			tmp = len;
		}
	}
	return (index);
}
