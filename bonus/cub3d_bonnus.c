/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonnus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:46:02 by mmondad           #+#    #+#             */
/*   Updated: 2024/10/12 20:15:43 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	clean_line(t_info *info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	i--;
	while (is_space(line[i]))
		i--;
	if (info->width < ++i)
		info->width = i;
}

void	new_maps(t_info *info)
{
	int	i;

	i = 0;
	while (info->maps[i])
	{
		clean_line(info, info->maps[i]);
		info->maps[i] = strdup_new_map(info->maps[i], info);
		i++;
	}
}

void	init_texture(t_info *info)
{
	info->texture[0].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/mur_1.xpm", &info->texture[0].w,
			&info->texture[0].h);
	info->texture[0].image = mlx_get_data_addr(info->texture[0].xpm_ptr,
			&info->texture[0].bet_pxl, &info->texture[0].size_line,
			&info->texture[0].endn);
	info->texture[1].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/mur_2.xpm", &info->texture[1].w,
			&info->texture[1].h);
	info->texture[1].image = mlx_get_data_addr(info->texture[1].xpm_ptr,
			&info->texture[1].bet_pxl, &info->texture[1].size_line,
			&info->texture[1].endn);
	info->texture[2].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/ps3.xpm", &info->texture[2].w,
			&info->texture[2].h);
	info->texture[2].image = mlx_get_data_addr(info->texture[2].xpm_ptr,
			&info->texture[2].bet_pxl, &info->texture[2].size_line,
			&info->texture[2].endn);
	info->texture[3].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/prison_lux1.xpm", &info->texture[3].w,
			&info->texture[3].h);
	info->texture[3].image = mlx_get_data_addr(info->texture[3].xpm_ptr,
			&info->texture[3].bet_pxl, &info->texture[3].size_line,
			&info->texture[3].endn);
	info->texture[4].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/bonus_textures/port_f.xpm", &info->texture[4].w,
			&info->texture[4].h);
	info->texture[4].image = mlx_get_data_addr(info->texture[4].xpm_ptr,
			&info->texture[4].bet_pxl, &info->texture[4].size_line,
			&info->texture[4].endn);
	info->texture[5].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/bonus_textures/port_o.xpm", &info->texture[5].w,
			&info->texture[5].h);
	info->texture[5].image = mlx_get_data_addr(info->texture[5].xpm_ptr,
			&info->texture[5].bet_pxl, &info->texture[5].size_line,
			&info->texture[5].endn);
}

int	check_valide_mur(t_info *info)
{
	int	i;
	int	j;

	i = 1;
	while (info->maps[i] && i < info->last_line)
	{
		j = 1;
		while (info->maps[i][j])
		{
			if (info->maps[i][j] == '0')
			{
				if (!check_valid_caractere(info->maps[i + 1][j])
					|| !check_valid_caractere(info->maps[i - 1][j])
					|| !check_valid_caractere(info->maps[i][j + 1])
					|| !check_valid_caractere(info->maps[i][j - 1]))
					print_error("invalide maps\n");
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_element_maps(t_info *info)
{
	int	i;

	i = 0;
	while (info->maps[i])
	{
		if (!check_valide_mur(info))
			return (0);
		i++;
	}
	return (1);
}

int	mouve_mouse(int x, int y, t_info *info)
{
	static int	a;

	if (x > a)
		info->angle += 0.01;
	else if (x < a)
		info->angle -= 0.01;
	a = x;
	return (0);
}

void	*checker(t_info *info, void *data)
{
	if (!data)
		free_list(info, 1);
	return (data);
}

void	init_images(t_info *info)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open("./bonus/images.txt", O_RDONLY);
	y = 0;
	while (y < WEAPONS)
	{
		x = 0;
		while (x < 4)
		{
			line = get_next_line(fd, info);
			line[ft_strlen(line) - 1] = '\0';
			info->images[y][x].xpm_ptr = checker(info,
					mlx_xpm_file_to_image(info->mlx, line,
						&info->images[y][x].w, &info->images[y][x].h));
			info->images[y][x].image = checker(info,
					mlx_get_data_addr(info->images[y][x].xpm_ptr,
						&info->images[y][x].bet_pxl,
						&info->images[y][x].size_line,
						&info->images[y][x].endn));
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	info.mlx = NULL;
	info.garbage = NULL;
	if (ac != 2)
		print_error("arguments error\n");
	init_info(&info, ac, av);
	read_maps(&info);
	check_textures_path(&info);
	if (!info.path_ea || !info.path_so || !info.path_we || !info.path_no)
		print_error("path_error\n");
	new_maps(&info);
	check_extention_map(&info);
	check_wall_valide(&info);
	check_nbr_player(&info);
	if (!check_element_maps(&info))
	{
		printf("autre caractere\n");
		return (0);
	}
	init_window(&info);
	init_images(&info);
	init_texture(&info);
	mlx_hook(info.mlx_win, 17, 0, ft_exit, 0);
	mlx_hook(info.mlx_win, 2, 1L << 0, move_player, &info);
	mlx_hook(info.mlx_win, 6, 1 << 6, mouve_mouse, &info);
	mlx_loop(info.mlx);
	free_list(&info, 0);
}
