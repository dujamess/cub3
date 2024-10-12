/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_heelp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:15:50 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 21:17:31 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 && s2 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*strdup_new_map(char *str, t_info *info)
{
	int		i;
	char	*s1;

	s1 = ft_malloc(info->tmp + 2, info);
	i = 0;
	while (i < info->tmp)
	{
		s1[i] = ' ';
		i++;
	}
	i = 0;
	while (i < info->tmp)
	{
		if (ft_strlen(str) - 1 > i)
			s1[i] = str[i];
		i++;
	}
	s1[i++] = '\n';
	s1[i] = '\0';
	return (s1);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *str, t_info *info)
{
	int		i;
	char	*s1;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	s1 = ft_malloc(i + 1, info);
	i = 0;
	while (str[i])
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
