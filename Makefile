CC = cc
CFLAGS = -Wall -Wextra -Werror -L minilibx-linux/ -lmlx -L /usr/lib -lXext -lX11 -lm
LFLAGS = -L minilibx-linux/ -lmlx -L /usr/lib -lXext -lX11

SRCS = main.c \
utils.c \
img.c \
frac_mandelbrot.c \
frac_julia.c

OBJS := $(SRCS:%.c=%.o)

NAME = fractol

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
#	make -C minilibx-linux/
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
