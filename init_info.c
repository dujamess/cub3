/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:52:02 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 13:52:04 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
