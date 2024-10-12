#include "cub3d.h"


int ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		ft_isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int the_biggest_line(t_info *info)
{
    int index;
    int tmp;
    int len;
    int i;

    i = 0;
    tmp = ft_strlen(info->maps[i]);
    while (info->maps[++i])
    {
        len = ft_strlen(info->maps[i]);
        if (len > tmp)
        {
            index = i;
            tmp = len;
        }
    }
    return (index);
}

