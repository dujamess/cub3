/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisial_bonnus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:56:30 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 20:09:41 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

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

void	start_animation(t_info *info)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 4)
	{
		color = 0xFFFFFF - 170;
		x = 0;
		while (x < 170)
		{
			mlx_put_image_to_window(info->mlx, info->mlx_win,
				info->start_images[y].xpm_ptr, 300 + (120 * y), x);
			usleep(2 * 1400);
			x += 1;
			mlx_string_put(info->mlx, info->mlx_win, WIDTH / 2 - 50, HEIGHT / 2
				+ 50, color++, "click space to start");
		}
		y++;
	}
}

void	init_window(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "duva");
	init_start_images(info);
}
