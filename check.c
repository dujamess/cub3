/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:59:13 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 20:59:51 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	*checker(t_info *info, void *data)
{
	if (!data)
		free_list(info, 1);
	return (data);
}
