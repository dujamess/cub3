/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:52:04 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 14:04:29 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_movement(t_info *info, double step_x, double step_y)
{
	double	x;
	double	y;
	double	val;

	x = info->x_p + step_x;
	y = info->y_p + step_y;
	val = 5;
	if (info->maps[(int)(info->y_p / TILE_SIZE)][(int)((x + val)
			/ TILE_SIZE)] != '1' && info->maps[(int)(info->y_p
			/ TILE_SIZE)][(int)((x - val) / TILE_SIZE)] != '1')
		info->x_p = x;
	if (info->maps[(int)((y + val) / TILE_SIZE)][(int)(info->x_p
			/ TILE_SIZE)] != '1' && info->maps[(int)((y - val)
			/ TILE_SIZE)][(int)(info->x_p / TILE_SIZE)] != '1')
		info->y_p = y;
}

void	update_door_stat(t_info *info)
{
	int	x;
	int	y;

	x = (int)info->x_p / TILE_SIZE;
	y = (int)info->y_p / TILE_SIZE;
	if (info->door_stat && info->maps[y][x] == 'P')
		info->door_stat = 1;
	else if (++info->door_stat > 1)
		info->door_stat = 0;
}

int	move_player(int c, t_info *info)
{
	if (c == 65363)
		info->angle += 0.1;
	if (c == 65361)
		info->angle -= 0.1;
	if (info->angle < 0)
		info->angle += 2 * M_PI;
	if (info->angle > 2 * M_PI)
		info->angle -= 2 * M_PI;
	if (c == ABOVE)
		update_movement(info, cos(info->angle) * SPEED, sin(info->angle)
			* SPEED);
	else if (c == LOWEST)
		update_movement(info, -cos(info->angle) * SPEED, -sin(info->angle)
			* SPEED);
	else if (c == RIGHT)
		update_movement(info, cos(info->angle + M_PI / 2) * SPEED,
			sin(info->angle + M_PI / 2) * SPEED);
	else if (c == LEFT)
		update_movement(info, cos(info->angle - M_PI / 2) * SPEED,
			sin(info->angle - M_PI / 2) * SPEED);
	else if (c == 65307)
		exit(0);
	return (0);
}

int	is_player(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
