/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonnus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:52:04 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 14:17:04 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	update_movement(t_info *info, double step_x, double step_y)
{
	double	x;
	double	y;
	double	x_p;
	double	y_p;
	double	val;

	x = info->x_p + step_x;
	y = info->y_p + step_y;
	val = 5;
	if (info->maps[(int)(info->y_p / TILE_SIZE)][(int)((x + val)
			/ TILE_SIZE)] != '1' && info->maps[(int)(info->y_p
			/ TILE_SIZE)][(int)((x - val) / TILE_SIZE)] != '1')
	{
		if (!is_opened(info, info->maps[(int)(info->y_p / TILE_SIZE)][(int)((x
						+ val) / TILE_SIZE)], (int *)&x) && !is_opened(info,
				info->maps[(int)(info->y_p / TILE_SIZE)][(int)((x - val)
					/ TILE_SIZE)], (int *)&x))
			info->x_p = x;
	}
	if (info->maps[(int)((y + val) / TILE_SIZE)][(int)(info->x_p
			/ TILE_SIZE)] != '1' && info->maps[(int)((y - val)
			/ TILE_SIZE)][(int)(info->x_p / TILE_SIZE)] != '1')
	{
		if (!is_opened(info, info->maps[(int)((y + val)
					/ TILE_SIZE)][(int)(info->x_p / TILE_SIZE)], (int *)&y)
			&& !is_opened(info, info->maps[(int)((y - val)
					/ TILE_SIZE)][(int)(info->x_p / TILE_SIZE)], (int *)&y))
			info->y_p = y;
	}
	if (fabs(step_x) > fabs(step_y))
	{
		if (step_x < 0)
			x_p = (info->x_p / TILE_SIZE) - 1;
		else
			x_p = (info->x_p / TILE_SIZE) + 1;
		y_p = info->y_p / TILE_SIZE;
	}
	else
	{
		if (step_y < 0)
			y_p = (info->y_p / TILE_SIZE) - 1;
		else
			y_p = (info->y_p / TILE_SIZE) + 1;
		x_p = info->x_p / TILE_SIZE;
	}
	if (info->maps[(int)(info->y_p / TILE_SIZE)][(int)(info->x_p
			/ TILE_SIZE)] == 'P')
	{
		if (info->maps[(int)y_p][(int)x_p] != '1'
			&& info->maps[(int)y_p][(int)x_p] != 'P')
		{
			info->x_p = x_p * TILE_SIZE;
			info->y_p = y_p * TILE_SIZE;
		}
		else
		{
			info->x_p = x - step_x;
			info->y_p = y - step_y;
		}
	}
}

void	update_door_stat(t_info *info)
{
	int	x;
	int	y;

	x = (int)info->x_p / TILE_SIZE;
	y = (int)info->y_p / TILE_SIZE;
	if (info->door_stat && info->maps[y][x] == 'P')
	{
		info->door_stat = 1;
		return ;
	}
	else if (++info->door_stat > 1)
		info->door_stat = 0;
	info->index_y--;
}

void	bonus_hook(t_info *info, int c)
{
	if (c == 111 && info->index_y == 2)
		update_door_stat(info);
	else if (c == 32)
	{
		mlx_loop_hook(info->mlx, rendering_2d, info);
		if (++info->index_y >= WEAPONS)
			info->index_y = 0;
	}
	else if (c == 112)
		info->gun = 1;
}

int	move_player(int c, t_info *info)
{
	bonus_hook(info, c);
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
