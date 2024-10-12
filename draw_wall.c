/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:04:19 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 21:05:01 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing_skay(t_info *info, double z)
{
	int	y;

	y = 0;
	while (y < info->point_depart)
	{
		my_mlx_pixel_put(info, z, y, info->c_color_int);
		y++;
	}
}

void	drawing_wall_vertical(t_info *info, int flag, double j)
{
	int	x;
	int	y;
	int	index;

	if (info->door_flag[0])
		flag = info->door_flag[0];
	x = (int)(info->texture[flag].w * info->intersection_x / 60)
		% info->texture[flag].w;
	y = j;
	index = ((y * info->texture[flag].size_line) + (x
				* (info->texture[flag].bet_pxl / 8)));
	if (info->texture[flag].size_line * info->texture[flag].h > index
		&& index > flag)
		info->color = *(int *)(info->texture[flag].image + index);
	else
		info->color = 0;
}

void	drawing_wall_horizantal(t_info *info, int flag, double j)
{
	int	x;
	int	y;
	int	index;

	if (info->door_flag[0])
		flag = info->door_flag[0];
	y = j;
	x = (int)(info->texture[flag].w * info->intersection_y / 60)
		% info->texture[flag].w;
	index = ((y * info->texture[flag].size_line) + (x
				* (info->texture[flag].bet_pxl / 8)));
	if (info->texture[flag].size_line * info->texture[flag].h > index
		&& index > flag)
		info->color = *(int *)(info->texture[flag].image + index);
	else
		info->color = 0;
}

void	drawing_floor(t_info *info, double z)
{
	int	j;

	j = 0;
	while (info->point_depart < HEIGHT)
	{
		my_mlx_pixel_put(info, (int)z, (int)info->point_depart,
			info->f_color_int);
		info->point_depart++;
		j += info->step;
	}
}

void	drawing_all_wall(t_info *info, double j)
{
	if (info->flag == 0)
	{
		if (info->check == 1 || info->check == 2)
			drawing_wall_vertical(info, 1, j);
		else
			drawing_wall_vertical(info, 0, j);
	}
	else
	{
		if (info->check == 1 || info->check == 4)
			drawing_wall_horizantal(info, 3, j);
		else
			drawing_wall_horizantal(info, 2, j);
	}
}
