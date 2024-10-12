/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:18:16 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 21:24:23 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid_caractere(char c)
{
	if (c != '1' && c != '0' && c != 'S' && c != 'N' && c != 'E' && c != 'W')
		return (0);
	return (1);
}

int	ft_check_crct(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]) && str[i] != '1' && str[i] != '0' && str[i] != 'S'
			&& str[i] != 'N' && str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	check_collone(char *maps)
{
	if ((!is_space(maps[0]) && maps[0] != '1')
		|| (!is_space(maps[ft_strlen(maps) - 2])
			&& maps[ft_strlen(maps) - 2] != '1') || !ft_check_crct(maps))
		return (0);
	return (1);
}

int	check_valide_char(char c)
{
	if (c != ' ' && c != '\n' && c != 'S' && c != 'W' && c != 'N' && c != 'E'
		&& c != '0' && c != '1')
		return (0);
	return (1);
}

void	check_wall_valide(t_info *info)
{
	int	i;

	i = 0;
	while (info->maps[i])
	{
		if (is_map(info->maps[i]))
		{
			if (!ft_check_crct((info->maps[i])))
				print_error("invalid_caracter\n");
			if (is_map(info->maps[i]))
				info->last_line = i;
			if (check_ligne(info->maps[0]) == 0)
				print_error("wall_line_1\n");
			if (check_collone(info->maps[i]) == 0)
			{
				print_error("wall_collone\n");
			}
		}
		i++;
	}
	if (check_ligne(info->maps[info->last_line]) == 0)
		print_error("wall_last_line\n");
}
