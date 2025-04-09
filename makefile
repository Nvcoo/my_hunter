##
## EPITECH PROJECT, 2024
## Untitled (Workspace)
## File description:
## makefile
##

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -I./include

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

SRC =	./src/my_hunter.c \
		./src/my.c \
		./src/cars.c \
		./src/cars_two.c \
		./src/cars_three.c \

OBJ = $(SRC:.c=.o)

NAME = my_hunter

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
