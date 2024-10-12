/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:24:29 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 21:25:35 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(char *str, int i, int sign)
{
	int	result;

	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if ((str[i + 1] < '0' || str[i + 1] > '9'))
			print_error("color_error1");
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if ((double)result * 10 + (str[i] - 48) * sign > 2147483647
			|| ((double)result * 10 + (str[i] - 48)) * sign < -2147483648)
			print_error("color_error2");
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] && !is_space(str[i]))
		print_error("color_error3");
	return (result * sign);
}

void	size_maps(t_info *info, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < info->size_map)
	{
		line = get_next_line(fd, info);
		if (info->tmp < ft_strlen2(line))
			info->tmp = ft_strlen2(line);
		info->maps[i] = ft_strdup(line, info);
		if (i == info->size_map - 1)
			info->maps[i] = ft_strjoin(info->maps[i], "\n", info);
		i++;
	}
	info->maps[i] = NULL;
}

void	read_maps(t_info *info)
{
	int		fd;

	info->size_map = 0;
	fd = open(info->map_name, O_RDONLY);
	if (fd < 0)
	{
		printf("file invalide : %s\n", info->map_name);
		exit(2);
	}
	while (get_next_line(fd, info))
		info->size_map++;
	close(fd);
	info->maps = ft_malloc(sizeof(char *) * (info->size_map + 1), info);
	fd = open(info->map_name, O_RDONLY);
	if (fd < 0)
		return ;
	size_maps(info, fd);
}

int	check_ligne(char *maps)
{
	int	i;

	i = 0;
	while (maps[i])
	{
		if (maps[i] != '1' && maps[i] != ' ' && maps[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
