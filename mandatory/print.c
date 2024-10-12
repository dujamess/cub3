#include "cub3d.h"

void    ft_putstr(char *str)
{
    while (str && *str)
        write(1, str++, 1);
}

void    print_error(char *str)
{
    write(2, "Error\n", 6);
    while (str && *str)
        write(2, str++, 1);
    exit(1);
}
