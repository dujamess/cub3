

/*          unused functions         */


int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}

char *ft_itoa_base(int value, int base)
{
	if (base < 2 || base > 16) return NULL;

	char *str;
	unsigned int num;
	int len = 0;
	char *base_chars = "0123456789ABCDEF";

	// Gestion des nombres négatifs pour base 10
	if (value < 0 && base == 10) {
		num = -value;
		len++;
	} else {
		num = value;
	}

	// Calcul de la longueur de la chaîne
	unsigned int temp = num;
	do {
		temp /= base;
		len++;
	} while (temp != 0);

	// Allocation de la chaîne (1 pour le '\0')
	str = malloc(len + 1);
	if (!str) return NULL;

	str[len] = '\0'; // Terminateur de chaîne

	// Remplissage de la chaîne en partant de la fin
	while (len > 0) {
		str[--len] = base_chars[num % base];
		num /= base;
	}

	// Si c'est un nombre négatif et base 10, ajout du signe
	if (value < 0 && base == 10) {
		str[0] = '-';
	}

	return str;
}

int putnum(long num)
{
	int base = 16;
	char *b = "0123456789abcdef";
	if (num <0 && base == 10)
		return write(1, "-", 1) + putnum(num*-1);
	if (num <0 && base == 16)
		return putnum((unsigned int)num);
	if (num/base==0)
		return write(1, &b[num%base], 1);
	return putnum(num/base) + putnum(num%base);
}

void	design_point_haut(t_info *info)
{
	int	x;
	int y;
	info->distance_ax = (info->distance_ax) + 60 / - tan((info->angle));
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			my_mlx_pixel_put(info, info->distance_ax + x, info->distance_ay + y - 60, 0x5f0000);
			x++;
		}
		y++;
	}
}

void	render_player(t_info *info, int color)
{
	int	x;
	int	y;
	int x_p;
	int y_p;

	x_p = (int)((MINIMAP_SIZE / info->width) * (info->x_p / 60));
	y_p = (int)((MINIMAP_SIZE / (info->last_line + 1)) * (info->y_p / 60));
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			my_mlx_pixel_put(info, x_p + x, y_p + y, color);
			my_mlx_pixel_put(info, x_p - x, y_p + y, color);
			my_mlx_pixel_put(info, x_p - x, y_p - y, color);
			my_mlx_pixel_put(info, x_p + x, y_p - y, color);
			x++;
		}
		y++;
	}
}

void    pinte_point(t_info *info)
{
	int x;
	int y;
	int  color = 0x141414;

	y = 0;
	while (y < 2)
	{
		x = 0;
		while (x < 2)
		{
			my_mlx_pixel_put(info, (info->intersection_x / 3) + x, (info->intersection_y / 3) + y, color);
			x++;
		}
		y++;
	}
}

void	draw_square_t(t_info *info)
{
	int x;
	int y;

	if (info->distance_ty / 60 > info->last_line + 1 || info->distance_ty < 0)
		return ;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			my_mlx_pixel_put(info, info->distance_tx + x, info->distance_ty + y, 0x03fcf4);
			x++;
		}
		y++;
	}
}

double	ft_abs(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}

// void	check_intersections_hor(t_info *info, double angle)
// {
// 	int	x;
// 	int	y;

// 	x = (int)info->distance_ax / 60;
// 	y = (int)info->distance_ay / 60;
// 	while ((info->distance_ay / 60 < info->last_line && info->distance_ay / 60 >= 0)
// 		&& (info->distance_ax / 60 < info->width && info->distance_ax / 60 >= 0))
// 	{
// 		if (info->maps[y][x] == '1' && is_opened(info, info->maps[y][x]))
// 		{
// 			info->hitwall_hor_x = info->distance_ax;
// 			info->hitwall_hor_y = info->distance_ay;
// 			return ;
// 		}
// 		if (info->check < 3)
// 		{
// 			info->distance_ax = (info->distance_ax + (60 / - tan((angle))));
// 			info->distance_ay -= 60;
// 		}
// 		else
// 		{
// 			info->distance_ax = (info->distance_ax + (60 /  tan((angle))));
// 			info->distance_ay += 60;
// 		}
// 		x = (int)info->distance_ax / 60;
// 		y = (int)info->distance_ay / 60;
// 	}
//     info->hitwall_hor_x = info->distance_ax;
// 	info->hitwall_hor_y = info->distance_ay;
// }

