/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:54:25 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 22:05:32 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rendering_2d_1(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i <= info->last_line)
	{
		j = 0;
		while (j < info->width)
		{
			if (j < info->width && i <= info->last_line
				&& is_player(info->maps[i][j]))
			{
				if (!info->x_p)
				{
					info->y_p = i * TILE_SIZE + 2;
					info->x_p = j * TILE_SIZE + 2;
					info->player = info->maps[i][j];
					init_angle(info);
				}
			}
			j++;
		}
		i++;
	}
}

int	rendering_2d(t_info *info)
{
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->save = mlx_get_data_addr(info->img, &info->bits_per_pixel,
			&info->line_length, &info->endian);
	if (info->angle < 0)
		info->angle += 2 * M_PI;
	if (info->angle > 2 * M_PI)
		info->angle -= 2 * M_PI;
	rendering_2d_1(info);
	draw_vector(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
	mlx_destroy_image(info->mlx, info->img);
	return (0);
}
