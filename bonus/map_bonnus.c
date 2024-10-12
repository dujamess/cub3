/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonnus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:03:51 by mmondad           #+#    #+#             */
/*   Updated: 2024/10/12 14:16:50 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	draw_square(t_info *info)
{
	int				y;
	int				x;
	static double	count;

	if (count < 180)
		info->square_color = (int)count;
	else
	{
		if (info->square_color)
			info->square_color -= 0.3;
		if (count > 360 || info->square_color < 0)
			count = 0;
	}
	count += 0.3;
	y = 0;
	while (y <= SQUARE_SIZE)
	{
		x = 0;
		while (x <= SQUARE_SIZE)
		{
			my_mlx_pixel_put(info, 10 + x, 10 + y, (int)info->square_color);
			x++;
		}
		y++;
	}
}

void	add_player(t_info *info)
{
	int	x_p;
	int	y_p;
	int	x;
	int	y;

	x_p = 10 + (SQUARE_SIZE / 2) - (PLAYER_SIZE / 2);
	y_p = 10 + (SQUARE_SIZE / 2) - (PLAYER_SIZE / 2);
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			my_mlx_pixel_put(info, x_p + x, y_p + y, 0xebd234);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_info *info)
{
	double	unit_size;
	double	p_map_x;
	double	p_map_y;
	int		y;
	int		x;
	int		map_x;
	int		map_y;

	unit_size = SQUARE_SIZE / info->width;
	p_map_x = (info->x_p / 60) - (SQUARE_SIZE / (2 * unit_size));
	p_map_y = (info->y_p / 60) - (SQUARE_SIZE / (2 * unit_size));
	draw_square(info);
	y = 0;
	while (y < SQUARE_SIZE)
	{
		x = 0;
		while (x < SQUARE_SIZE)
		{
			map_x = floor(p_map_x + (x / unit_size));
			map_y = floor(p_map_y + (y / unit_size));
			if (map_x >= 0 && map_x < info->width && map_y >= 0
				&& map_y < (info->last_line + 1))
			{
				if (info->maps[map_y][map_x] == '1'
					|| is_space(info->maps[map_y][map_x]))
					my_mlx_pixel_put(info, 10 + x, 10 + y, 0);
				else if (info->maps[map_y][map_x] == 'P')
					my_mlx_pixel_put(info, 10 + x, 10 + y, 0xff0000);
				else
					my_mlx_pixel_put(info, 10 + x, 10 + y, 0xffffff);
			}
			x++;
		}
		y++;
	}
	add_player(info);
}
