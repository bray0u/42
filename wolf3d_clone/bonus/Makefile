# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 20:05:56 by gexbraya          #+#    #+#              #
#    Updated: 2015/03/10 19:22:56 by gexbraya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mkart
CC = gcc
CFLAGS = -Ofast -Wall -Wextra -Werror
SDIR = ./src/
IDIR = ./includes/
LIBS = -lmlx -framework OpenGL -framework AppKit -lm
SRC = $(SDIR)main.c $(SDIR)init.c $(SDIR)draw.c  $(SDIR)draw2.c \
	  $(SDIR)key1.c $(SDIR)key2.c $(SDIR)bfunc.c $(SDIR)free.c \
	  $(SDIR)handle_fps.c $(SDIR)draw3.c $(SDIR)init2.c $(SDIR)finish.c \
	  $(SDIR)gettime.c
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
