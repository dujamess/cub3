/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:58:55 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 19:58:56 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr(char *str)
{
	while (str && *str)
		write(1, str++, 1);
}

void	print_error(char *str)
{
	write(2, "Error\n", 6);
	while (str && *str)
		write(2, str++, 1);
	exit(1);
}
