/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-29 12:04:56 by mmondad           #+#    #+#             */
/*   Updated: 2024-08-29 12:04:56 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_back_h(t_garbage **list, t_garbage *new_node)
{
	t_garbage	*tmp;

	tmp = *list;
	if (*list)
	{
		while ((*list)->next)
			(*list) = (*list)->next;
		(*list)->next = new_node;
		*list = tmp;
	}
	else
		(*list) = new_node;
}

void	new_fnode(void *data, t_info *info)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (!node)
		free_list(info, 1);
	node->data = data;
	node->next = NULL;
	add_back_h(&(info->garbage), node);
}
