
CC = cc
CFLAGS = -Ofast  -fsanitize=address -g3

SRC = cub3d.c get_next_line.c init_info.c print.c ft_split.c \
      parssing.c parssing1.c utils.c utils1.c garbage_collector.c free.c\
	  player.c render_maps.c inisial.c distance.c draw.c colors.c
OBJT = $(SRC:.c=.o)

NAME = cub3d

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
