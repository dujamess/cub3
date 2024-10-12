/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_file_bonnus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:30:50 by mmondad           #+#    #+#             */
/*   Updated: 2024/10/12 14:16:02 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

int	is_opened(t_info *info, char c, int *x)
{
	if (!info->door_stat && c == 'P')
		return (1);
	return (0);
}

int	door_validator(t_info *info, int x, int y)
{
	if (info->maps[y][x + 1] == 'P' || info->maps[y][x - 1] == 'P'
		|| info->maps[y - 1][x] == 'P' || info->maps[y + 1][x] == 'P')
		return (0);
	if (info->maps[y][x + 1] == '1' && info->maps[y][x - 1] == '1'
		&& info->maps[y - 1][x] != '1' && info->maps[y + 1][x] != '1')
		return (1);
	if (info->maps[y][x + 1] != '1' && info->maps[y][x - 1] != '1'
		&& info->maps[y - 1][x] == '1' && info->maps[y + 1][x] == '1')
		return (1);
	return (0);
}
