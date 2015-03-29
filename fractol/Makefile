# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 20:05:56 by gexbraya          #+#    #+#              #
#    Updated: 2015/03/27 16:58:38 by gexbraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SDIR = ./srcs/
IDIR = ./includes/
LIBS = -lmlx -framework OpenGL -framework AppKit
SRC = $(SDIR)main.c $(SDIR)draw.c $(SDIR)color.c $(SDIR)print.c \
	  $(SDIR)fractal.c $(SDIR)init.c $(SDIR)key1.c $(SDIR)key2.c \
	  $(SDIR)key3.c $(SDIR)bfunc.c $(SDIR)options.c $(SDIR)fractal2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo " - Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -I$(IDIR) $^ -o $(NAME) $(LIBS)
	@echo "Done."

%.o:%.c
	@echo " - Creating $<..."
	@$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $@

clean:
	@echo " - Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo " - Cleaning binary..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re
