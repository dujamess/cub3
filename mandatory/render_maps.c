/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:54:25 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 13:12:28 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    put_pixels_as_image(t_info *info, int i, int j, long color)
{
	int x;
	int y;

	x = 0;
	while (x < (MINIMAP_SIZE / (info->last_line + 1)) - 1)
	{
		y = 0;
		while (y < (MINIMAP_SIZE / info->width) - 1)
		{
			my_mlx_pixel_put(info, (j * (MINIMAP_SIZE / info->width)) + y, (i * (MINIMAP_SIZE / (info->last_line + 1))) + x, color);
			y++;
		}
		x++;
	}
}

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;
	if (y < 0 || y > HEIGHT || x < 0 || x > WIDTH)
		return ;
	dst = info->save + (y * info->line_length + x * (info->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	set_pic(t_info *info)
{
	static int count;

	if (count < 15 && info->gun)
		info->index_x = 0;
	else if (count < 30 && info->gun)
		info->index_x = 1;
	else if (count < 45 && info->gun)
		info->index_x = 2;
	else if (count < 60 && info->gun)
		info->index_x = 3;
	else
	{
		info->index_x = 0;
		info->gun = 0;
		count = 0;
	}
	count++;
}

void	animation(t_info *info)
{
	int y;
	int x;
	int var2;
	int color;

	set_pic(info);
	y = 0;
	int offset_x = (WIDTH / 2) - (info->images[info->index_y][info->index_x].w / 2) + 100;
	int offset_y = HEIGHT - (info->images[info->index_y][info->index_x].h) + ((info->images[info->index_y][info->index_x].h) / 2) - 60;
	while (y < info->images[info->index_y][info->index_x].h)
	{
		x = 0;
		while (x < info->images[info->index_y][info->index_x].w)
		{
			var2 = ((y * info->images[info->index_y][info->index_x].size_line) + (x * (info->images[info->index_y][info->index_x].bet_pxl / 8)));
			color = *(int*)(info->images[info->index_y][info->index_x].image + var2);
			if (color != -16777216)
				my_mlx_pixel_put(info, x + offset_x, y + offset_y, color);
			x++;
		}
		y++;
	}
	
}

int    rendering_2d(t_info *info)
{
	int	i;
	int	j;

	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->save = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_length,
								&info->endian);
	if (info->angle < 0)
		info->angle += 2 * M_PI;
	if (info->angle > 2 * M_PI)
		info->angle -= 2 * M_PI;
	i = 0;
	while (i <= info->last_line)
	{
		j = 0;
		while (j < info->width)
		{
			if (info->maps[i][j] == 'P')
			{
				info->x_door = j;
				info->y_door = i;
			}
			if ( j < info->width && i <= info->last_line && is_player(info->maps[i][j]))
			{
				if(!info->x_p)
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
	draw_vector(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
	mlx_destroy_image (info->mlx, info->img);
	return (0);
}
