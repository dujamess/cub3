/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:24:26 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 22:10:55 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(char *str)
{
	while (*str && is_space(*str))
		str++;
	if (*str)
		return (1);
	return (0);
}

void	check_textures_path(t_info *info)
{
	while (*info->maps)
	{
		if (!strcmp_path(*info->maps, "NO", 2))
		{
			if (info->path_no)
				print_error("error_NO");
			info->path_no = ft_strdup(set_path(*info->maps), info);
		}
		else if (!strcmp_path(*info->maps, "WE", 2))
		{
			if (info->path_we)
				print_error("error_we");
			info->path_we = ft_strdup(set_path(*info->maps), info);
		}
		else if (!strcmp_path(*info->maps, "SO", 2))
		{
			if (info->path_so)
				print_error("error_so");
			info->path_so = ft_strdup(set_path(*info->maps), info);
		}
		else if (!strcmp_path(*info->maps, "EA", 2))
		{
			if (info->path_ea)
				print_error("error_ea");
			info->path_ea = ft_strdup(set_path(*info->maps), info);
		}
		else if (check_colors(info))
		{
		}
		else if (is_map(*info->maps))
			break ;
		info->size_map--;
		info->maps++;
	}
}
