# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fweichse <fweichse@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 12:21:48 by fweichse          #+#    #+#              #
#    Updated: 2023/09/28 12:23:18 by fweichse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR =	./src/
INC_DIR =	./includes/

SRC_FILES =		main.c \
				utils.c \
				img.c \
				frac_mandelbrot.c \
				frac_julia.c

SRCS =			$(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_OBJS =		$(SRCS:.c=.o)

# Compiler settings
CC =			cc
CFLAGS =		-Wall -Wextra -Werror -Ofast -w
IFLAGS =		-I $(INC_DIR)

# Target
NAME =			fractol

all: $(NAME)	

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) -o $(NAME) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $(IFLAGS) $< -o $@

clean:
	rm -rf $(SRC_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus