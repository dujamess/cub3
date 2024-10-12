CFLAGS	= -Ofast -fsanitize=address -g3
CC      = cc
NFLAGS = -lmlx -lXext -lX11
SRCS_C    = bonus/colors_bonnus.c bonus/cub3d_bonnus.c bonus/distance_bonnus.c bonus/door_file_bonnus.c\
			bonus/draw_bonnus.c bonus/free_bonnus.c bonus/ft_split_bonnus.c bonus/garbage_collector_bonnus.c\
			bonus/get_next_line_bonnus.c bonus/inisial_bonnus.c bonus/init_info_bonnus.c bonus/map_bonnus.c\
			bonus/parssing1_bonnus.c bonus/parssing_bonnus.c bonus/player_bonnus.c bonus/print_bonnus.c\
			bonus/render_maps_bonnus.c bonus/tmp_file_bonnus.c bonus/utils1_bonnus.c bonus/utils_bonnus.c\
			bonus/validators_bonnus.c
SRC	= colors.c cub3d.c distance.c draw.c free.c ft_split.c garbage_collector.c get_next_line.c \
	  inisial.c init_info.c parssing1.c parssing.c player.c print.c render_maps.c utils1.c utils.c

NAME = cub3d
NAME_C = cub3d_bonus
OBJT = $(SRC:.c=.o)
OBJS_C 	= $(SRCS_C:.c=.o)
all : $(NAME)

$(NAME): $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) $(NFLAGS) -o $(NAME) 

bonus: $(NAME_C)

$(NAME_C): $(OBJS_C)
		   $(CC) $(CFLAGS) $(OBJS_C) $(NFLAGS) -o $(NAME_C)
%.o: %.c
	$(CC) $(CFLAGS) -I -Imlx_linux -O3 -c $< -o $@
clean : 
		rm -f $(OBJT) $(OBJS_C)
fclean : clean
		rm -f $(NAME) $(NAME_C)
re : fclean all