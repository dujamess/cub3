/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:56:30 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 21:18:42 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_angle(t_info *info)
{
	if (info->player == 'N')
		info->angle = 3 * M_PI / 2;
	else if (info->player == 'W')
		info->angle = M_PI;
	else if (info->player == 'S')
		info->angle = M_PI / 2;
	else if (info->player == 'E')
		info->angle = 0;
}

void	conditions(t_info *info, double angle)
{
	if (angle >= 3 * M_PI / 2 && angle < 2 * M_PI)
		info->check = 1;
	else if (angle < 3 * M_PI / 2 && angle > M_PI)
		info->check = 2;
	else if (angle < M_PI / 2 && angle > 0)
		info->check = 4;
	else if (angle > M_PI / 2 && angle < M_PI)
		info->check = 3;
}

void	init_window(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "duva");
}

void	init_texture(t_info *info)
{
	info->texture[0].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/texture/mur_1.xpm", &info->texture[0].w,
			&info->texture[0].h);
	info->texture[0].image = mlx_get_data_addr(info->texture[0].xpm_ptr,
			&info->texture[0].bet_pxl, &info->texture[0].size_line,
			&info->texture[0].endn);
	info->texture[1].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/texture/mur_2.xpm", &info->texture[1].w,
			&info->texture[1].h);
	info->texture[1].image = mlx_get_data_addr(info->texture[1].xpm_ptr,
			&info->texture[1].bet_pxl, &info->texture[1].size_line,
			&info->texture[1].endn);
	info->texture[2].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/texture/ps3.xpm", &info->texture[2].w,
			&info->texture[2].h);
	info->texture[2].image = mlx_get_data_addr(info->texture[2].xpm_ptr,
			&info->texture[2].bet_pxl, &info->texture[2].size_line,
			&info->texture[2].endn);
	info->texture[3].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/texture/prison_lux1.xpm", &info->texture[3].w,
			&info->texture[3].h);
	info->texture[3].image = mlx_get_data_addr(info->texture[3].xpm_ptr,
			&info->texture[3].bet_pxl, &info->texture[3].size_line,
			&info->texture[3].endn);
}
