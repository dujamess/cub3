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

void    read_maps(t_info *info)
{
	int     fd;
	char    *line;
	int     i;

	i = 0;
	info->size_map = 0;
	if ((fd = open(info->map_name, O_RDONLY)) < 0)
	{
		printf("file invalide : %s\n", info->map_name);
		exit(2) ;
	}
	while(get_next_line(fd, info))
		info->size_map++;
	close(fd);
	info->maps = ft_malloc(sizeof(char *) * (info->size_map + 1), info);
	if ((fd = open(info->map_name, O_RDONLY)) < 0)
		return ;
	while(i < info->size_map)
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

int check_ligne(char *maps)
{
	int i;

	i = 0;
	while (maps[i])
	{
		if (maps[i] != '1' && maps[i] != ' ' && maps[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int check_valid_caractere(char c)
{
	if (c != '1' && c != '0' && c != 'S' && c != 'N'
			&& c != 'E' && c != 'W')
		return (0);
	return (1);
}

int ft_check_crct(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!is_space(str[i])
			&& str[i] != '1' && str[i] != '0' && str[i] != 'S' && str[i] != 'N'
			&& str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int check_collone(char *maps)
{
	if ((!is_space(maps[0]) && maps[0] != '1') || (!is_space(maps[ft_strlen(maps) - 2]) && maps[ft_strlen(maps) - 2] != '1') || !ft_check_crct(maps))
		return (0);
	return (1);
}

int check_valide_char(char c)
{
	if (c != ' ' && c != '\n' && c != 'S' &&  c != 'W'
		&& c != 'N' && c != 'E' && c != '0' && c != '1')
		return (0);
	return (1);
}

void    check_wall_valide(t_info *info)
{
	int i;

	i = 0;
	while (info->maps[i])
	{
		if (is_map(info->maps[i]))
		{ 
			if (!ft_check_crct((info->maps[i])))
				print_error("invalid_caracter\n");
			if(is_map(info->maps[i]))
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
