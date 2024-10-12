
CC = cc
CFLAGS = -Ofast  -fsanitize=address -g3

SRC = cub3d_bonnus.c get_next_line_bonnus.c init_info_bonnus.c print_bonnus.c ft_split_bonnus.c \
      parssing_bonnus.c parssing1_bonnus.c utils_bonnus.c utils1_bonnus.c garbage_collector_bonnus.c free_bonnus.c validators_bonnus.c\
	  player_bonnus.c render_maps_bonnus.c inisial_bonnus.c distance_bonnus.c draw_bonnus.c colors_bonnus.c map_bonnus.c door_file_bonnus.c
OBJT = $(SRC:.c=.o)

NAME = cub3d_bonnus

LIBS = -Lmlx -lbsd -lm -lmlx -lX11 -lXext
LDFLAGS = $(LIBS)

all: $(NAME)
$(NAME): $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJT)
fclean: clean
	rm -f $(NAME)

re: fclean all
