/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonnus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:16:43 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 17:59:10 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void    init_start_images(t_info *info)
{
    int w;
    int h;

    // info->start_images[0].xpm_ptr = mlx_xpm_file_to_image(info->mlx, "s.xpm", &w, &h);
    // info->start_images[1].xpm_ptr = mlx_xpm_file_to_image(info->mlx, "i.xpm", &w, &h);
    // info->start_images[2].xpm_ptr = mlx_xpm_file_to_image(info->mlx, "m.xpm", &w, &h);
    // info->start_images[3].xpm_ptr = mlx_xpm_file_to_image(info->mlx, "o.xpm", &w, &h);
    info->start_images[0].xpm_ptr = mlx_xpm_file_to_image(info->mlx, "./bonus/presentation_textures/presentation.xpm", &w, &h);
    mlx_put_image_to_window(info->mlx, info->mlx_win, info->start_images[0].xpm_ptr, 0, 0 );
}


void    init_info(t_info *info, int ac, char **av)
{
    info->ac = ac;
    info->gun = 0;
    info->width = 0;
    info->door_flag[0] = 0;
    info->door_flag[1] = 0;
    info->door_stat = 0;
    info->map_name = av[1];
    info->tmp = 0;
    info->path_ea = NULL;
    info->path_no = NULL;
    info->path_we = NULL;
    info->path_so = NULL;
    info->x_p = 0;
    info->index_x = 0;
    info->index_y = -1;
    info->y_p = 0;
    info->ceiling_color = NULL;
    info->floor_color = NULL;
    info->last_line = 0;
    info->dir_x = 0;
    info->dir_y = 0;
    info->c = ft_malloc(sizeof (int) * 3, info);
    info->f = ft_malloc(sizeof (int) * 3, info);
}
