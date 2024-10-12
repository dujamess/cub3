/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:31 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 21:12:38 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	norm(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	calcul_step(t_info *info, double count)
{
	info->lenght = (60 / (info->size * cos(count))) * ((WIDTH / 2)
			/ tan(0.523599));
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

void	draw_wall_game(t_info *info, double z)
{
	int		var;
	double	j;

	var = info->point_depart;
	j = 0;
	if (info->point_depart < 0)
	{
		j = info->step * (-info->point_depart);
		info->point_depart = 0;
	}
	while (info->point_depart < HEIGHT && info->point_depart <= info->lenght
		+ var)
	{
		drawing_all_wall(info, j);
		my_mlx_pixel_put(info, z, info->point_depart, info->color);
		info->point_depart++;
		j += info->step;
	}
}

void	drwa_floor_game(t_info *info, double z)
{
	while (info->point_depart < HEIGHT)
	{
		my_mlx_pixel_put(info, (int)z, (int)info->point_depart, 0);
		info->point_depart++;
	}
}

void	draw_vector(t_info *info)
{
	double	count;
	double	z;

	count = -M_PI / 6;
	z = 0;
	info->point_depart = 0;
	while (count < M_PI / 6)
	{
		conditions(info, norm(info->angle + count));
		calcul_distance(info, norm(info->angle + count));
		calcul_step(info, count);
		drawing_skay(info, z);
		draw_wall_game(info, z);
		drwa_floor_game(info, z);
		z += 1;
		count = count + RAD / (VIEW * 1.5);
		info->door_flag[0] = 0;
		info->door_flag[1] = 0;
	}
}
