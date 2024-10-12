/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:17:34 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 21:16:26 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, t_info *info)
{
	int		i;
	char	*s3;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_malloc(i + 1, info);
	j = 0;
	i = 0;
	while (s1 && s1[i])
	{
		s3[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	s3[j] = '\0';
	return (s3);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	*get_next_line(int fd, t_info *info)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*newline;
	char		*line;
	int			l;

	line = ft_strdup(buf, info);
	while (!(newline = ft_strchr(line, '\n')) && (l = read(fd, buf,
				BUFFER_SIZE)))
	{
		buf[l] = '\0';
		line = ft_strjoin(line, buf, info);
	}
	if (ft_strlen(line) == 0)
		return (NULL);
	if (newline)
	{
		ft_strcpy(buf, newline + 1);
		*(newline + 1) = '\0';
	}
	else
		buf[0] = '\0';
	return (line);
}
