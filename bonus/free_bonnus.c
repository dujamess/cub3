/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonnus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:15:27 by mmondad           #+#    #+#             */
/*   Updated: 2024/10/12 20:07:55 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	free_list(t_info *info, int i)
{
	t_garbage	*tmp;

	while (info->garbage)
	{
		tmp = info->garbage;
		info->garbage = info->garbage->next;
		free(tmp->data);
		free(tmp);
	}
	info->garbage = NULL;
	if (i)
		print_error("Error\n");
}

void	*ft_malloc(size_t size, t_info *info)
{
	char	*data;

	data = malloc(size);
	if (!data)
		free_list(info, 1);
	new_fnode(data, info);
	return ((void *)data);
}

int	ft_exit(void)
{
	exit(0);
}
