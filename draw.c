/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:31 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 18:01:55 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	norm(double	angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	calcul_step(t_info *info, double count)
{
	info->lenght = (60 / (info->size * cos(count))) * ((WIDTH/ 2) / tan(0.523599));
	info->point_depart = (HEIGHT / 2) - (info->lenght / 2);
	if (info->door_flag[0])
		info->step = (double)info->texture[4].h / (double)info->lenght;
	if (info->flag == 0)
	{
		if (info->check == 1 || info->check == 2)
			info->step = (double)info->texture[1].h / (double)info->lenght;
		else
			info->step = (double)info->texture[0].h / (double)info->lenght;
		}
	else
	{
		if (info->check == 1 || info->check == 4)
			info->step = (double)info->texture[3].h / (double)info->lenght;
		else
			info->step = (double)info->texture[2].h / (double)info->lenght;
	}
}

void	drawing_skay(t_info *info, double z)
{
	int y;
	
	y = 0;
	while (y < info->point_depart)
	{
		my_mlx_pixel_put(info, z, y,  info->c_color_int);
		y++;
	}
}

void	drawing_wall_vertical(t_info *info, int flag, double j)
{
	int x;
	int y;
	int index;

	if (info->door_flag[0])
		flag = info->door_flag[0];
	x = (int)(info->texture[flag].w * info->intersection_x / 60) % info->texture[flag].w ;
	y = j;
	index = ((y * info->texture[flag].size_line) + (x * (info->texture[flag].bet_pxl / 8)));
	if (info->texture[flag].size_line * info->texture[flag].h > index && index > flag)
		info->color = *(int*)(info->texture[flag].image + index);
	else
		info->color = 0;
}

void	drawing_wall_horizantal(t_info *info, int flag, double j)
{
	int x;
	int y;
	int index;
	
	if (info->door_flag[0])
		flag = info->door_flag[0];
	y = j;
	x = (int)(info->texture[flag].w * info->intersection_y / 60) % info->texture[flag].w;
	index = ((y * info->texture[flag].size_line) + (x * (info->texture[flag].bet_pxl / 8)));
	if (info->texture[flag].size_line * info->texture[flag].h > index && index > flag)
		info->color = *(int*)(info->texture[flag].image + index);
	else
		info->color = 0;
}
void	drawing_floor(t_info *info, double z)
{
	int	j;
	
	j = 0;
	while (info->point_depart < HEIGHT)
	{
		my_mlx_pixel_put(info, (int)z, (int)info->point_depart,  info->f_color_int);
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

void	draw_vector(t_info *info)
{
	double	count = - M_PI / 6;
	double z = 0;
	double j;
	int var;

	info->point_depart = 0;
	while (count < M_PI / 6)
	{
		conditions(info, norm(info->angle + count));
        calcul_distance(info, norm(info->angle + count));
		calcul_step(info, count);
		drawing_skay(info,z);
		var = info->point_depart;
		j = 0;
		if (info->point_depart < 0)
		{
			j = info->step * (-info->point_depart);
			info->point_depart = 0;
		}
		while (info->point_depart < HEIGHT && info->point_depart <= info->lenght  + var)
		{
			drawing_all_wall(info, j);
			my_mlx_pixel_put(info, z, info->point_depart, info->color);
			info->point_depart++;
			j += info->step;
		}
		while (info->point_depart < HEIGHT)
		{
			my_mlx_pixel_put(info, (int)z, (int)info->point_depart, 0);
			info->point_depart++;
		}
		z += 1;
		count = count + RAD / (VIEW * 1.5);
		info->door_flag[0] = 0;
		info->door_flag[1] = 0;
	}
}
