#include "cub3d.h"

int ft_isdegit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int strlen_pro(char *str, char flag)
{
	int count;

	count = 0;
	while (str && *str)
	{
		if (*str == flag && flag)
			count++;
		str++;
	}
	return (count);
}
int check_vergule( char *str, int   **tab, t_info *info)
{
	int i;
	int count;
	char **parts;

	count = 0;
	i = 0;
	if (strlen_pro(str, ',') != 2)
		return (0);
	if (!ft_isdegit(*str))
		return(0);
	parts = ft_split(str, ',', info);
	while(parts[i])
	{
		if (i > 3)
			return (0);
	   tab[0][i] = ft_atoi(parts[i], 0, 1);
	   if (tab[0][i] > 255)
			return (0);
		i++;
	}
	if (i < 3)
		return (0);
	return (1);
}

int	ft_atoi_s(const char *str)
{
	int				signe;
	int				i;
	long			result;

	i = 0;
	result = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		signe = signe * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result = result * signe;
	return ((int)result);
}

int    check_colors(t_info *info)
{
	if (!strcmp_path(*info->maps, "C", 1))
	{
		if (info->ceiling_color)
			print_error("ceiling_color");
		info->ceiling_color = ft_strdup(set_path(*info->maps), info);
		if (!check_vergule(info->ceiling_color,(int **)&(info->c), info))
			print_error("ceiling_color1");
		info->c_color_int = create_trgb(0, info->c[0], info->c[1], info->c[2]);
		return (1);
	}
	else if (!strcmp_path(*info->maps, "F", 1))
	{
		if (info->floor_color)
			print_error("floor_color");
		info->floor_color = ft_strdup(set_path(*info->maps), info);
		if (!check_vergule(info->floor_color, (int **)&(info->f), info))
			print_error("floor_color");
		info->f_color_int = create_trgb(0, info->f[0], info->f[1], info->f[2]);
		return (1);
	}
	return (0);
}

int is_map(char *str)
{
	while (*str && is_space(*str))
		str++;
	if (*str)
		return (1);
	return (0);
}

void    check_textures_path(t_info *info)
{
	while (*info->maps)
	{
		if (check_colors(info))
		{}
		else if (!strcmp_path(*info->maps, "NO", 2))
		{
			if (info->path_no)
				print_error("error_NO");
			info->path_no = ft_strdup(set_path(*info->maps), info);
		}
		else if (!strcmp_path(*info->maps, "WE", 2))
		{
			if (info->path_we)
				print_error("error_we");
			info->path_we = ft_strdup(set_path(*info->maps), info);
		}
		else if (!strcmp_path(*info->maps, "SO", 2))
		{
			if (info->path_so)
				print_error("error_so");
			info->path_so = ft_strdup(set_path(*info->maps), info);
		}
		else if (!strcmp_path(*info->maps, "EA", 2))
		{
			if (info->path_ea)
				print_error("error_ea");
			info->path_ea = ft_strdup(set_path(*info->maps), info);
		}
		else if (is_map(*info->maps))
			break;
		info->size_map--;
		info->maps++;
	}
}
