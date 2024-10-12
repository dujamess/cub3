/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_bonnus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:00:34 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 14:15:59 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	choose_door_image(t_info *info, int index)
{
	if (info->door_flag[index])
		info->door_flag[0] = 4 + info->door_stat;
	else
		info->door_flag[0] = 0;
}

void	compare_distance(t_info *info)
{
	double  PD;
	double	PE;

	PD = sqrt((pow(info->x_p - info->hitwall_hor_x, 2)) + (pow(info->y_p - info->hitwall_hor_y, 2)));
	PE = sqrt((pow(info->x_p - info->hitwall_vir_x, 2)) + (pow(info->y_p - info->hitwall_vir_y, 2)));
	if (PD > PE)
	{
		/* bonus */
		choose_door_image(info, 1);
		info->flag = 1;
		info->intersection_x = fabs(info->hitwall_vir_x);
		info->intersection_y = fabs(info->hitwall_vir_y);
		info->size = PE;
	}
	else
	{
		/* bonus */
		choose_door_image(info, 0);
		info->flag = 0;
        info->intersection_x = fabs(info->hitwall_hor_x);
		info->intersection_y = fabs(info->hitwall_hor_y);
		info->size = PD;
	}
}

void	check_intersections_hor(t_info *info, double angle)
{
	double	x;
	double	y;

	x = info->distance_ax / 60;
	
	while ((info->distance_ay / 60 < info->last_line && info->distance_ay / 60 >= 0)
		&& (info->distance_ax / 60 < info->width && info->distance_ax / 60 >= 0)
			)
	{
		if (info->maps[(int)(info->distance_ay / 60)][(int)(info->distance_ax / 60)] == '1'
			|| info->maps[(int)(info->distance_ay / 60)][(int)(info->distance_ax / 60)] == 'P')
		{
			if (info->maps[(int)(info->distance_ay / 60)][(int)(info->distance_ax / 60)] == 'P')
				info->door_flag[0] = 1;
			info->hitwall_hor_x = info->distance_ax;
			info->hitwall_hor_y = info->distance_ay;
			return ;
		}
		if (info->check < 3)
		{
			info->distance_ax = (info->distance_ax + (60 / - tan((angle))));
			info->distance_ay -= 60;
		}
		else
		{
			info->distance_ax = (info->distance_ax + (60 /  tan((angle))));
			info->distance_ay += 60;
		}
	}
    info->hitwall_hor_x = info->distance_ax;
	info->hitwall_hor_y = info->distance_ay;
}

void	check_intersections_vir(t_info *info, double angle)
{
	while (((info->distance_ty / 60) < info->last_line && info->distance_ty / 60 >= 0)
		&& ((info->distance_tx / 60) < info->width && info->distance_tx / 60 >= 0))
	{
		if (info->maps[(int)(info->distance_ty / 60)][(int)(info->distance_tx / 60)] == '1'
			|| info->maps[(int)(info->distance_ty / 60)][(int)(info->distance_tx / 60)] == 'P')
		{
			if (info->maps[(int)(info->distance_ty / 60)][(int)(info->distance_tx / 60)] == 'P')
				info->door_flag[1] = 1;
			info->hitwall_vir_x = info->distance_tx;
			info->hitwall_vir_y = info->distance_ty;
			return ;
		}
		if (info->check == 3 || info->check == 2)
		{
			info->distance_tx -= 60;
			info->distance_ty = info->y_p - (-info->distance_tx + info->x_p) * tan((angle));
		}
		else
		{
			info->distance_tx += 60;
			info->distance_ty = info->y_p - (-info->distance_tx + info->x_p) * tan((angle));
		}
	}
	info->hitwall_vir_x = info->distance_tx;
	info->hitwall_vir_y = info->distance_ty;
}

void	calcul_distance(t_info *info, double angle)
{
	if (info->check == 1 || info->check == 2)
		info->distance_ay = floor(info->y_p / 60) * 60 - pow(10, -10);
	else if (info->check == 3 || info->check == 4)
		info->distance_ay = floor(info->y_p / 60) * 60 + 60;
	info->distance_ax = info->x_p + (info->distance_ay - info->y_p) / tan((angle));
	if (info->check == 3 || info->check == 2)
		info->distance_tx = floor(info->x_p/60) * (60) - pow(10, -10);
	if (info->check == 4 || info->check == 1)
		info->distance_tx = floor(info->x_p/60) * (60) + 60;
	info->distance_ty = info->y_p - (-info->distance_tx + info->x_p) * tan((angle));
	check_intersections_hor(info, angle);
	check_intersections_vir(info, angle);
	compare_distance(info);
}
