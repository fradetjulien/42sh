##
## Makefile for  in /home/lenoir_g/rendu/template
##
## Made by Guillaume LENOIR
## Login   <lenoir_g@epitech.net>
##
## Started on  Mon Oct 24 09:14:27 2016 Guillaume LENOIR
## Last update Thu May 18 06:20:41 2017 LENOIR
##

SRC	= cd.c	\
	env.c	\
	piped.c	\
	env_func.c	\
	epur.c	\
	redir.c	\
	exec.c	\
	main.c	\
	prompt.c	\
	redirect.c	\
	classic.c

OBJ	= $(addprefix src/, $(SRC:.c=.o))

LDFLAGS = -L./lib/my/ -lmy -lncurses

CFLAGS	= -I./include/ -g

RM 	= rm -f

CC	= gcc

DIR	= lib/my

NAME	= 42sh

$(NAME): $(OBJ)
	@(cd $(DIR) && $(MAKE))
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	cd $(DIR) && ($(MAKE) clean)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	cd $(DIR) && ($(MAKE) clean)

re: lib fclean all

.PHONY: all clean fclean re lib
