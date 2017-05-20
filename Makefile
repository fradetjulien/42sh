##
## Makefile for  in /home/fradet_j/PSU/PSU_2016_minishell2
##
## Made by Julien Fradet
## Login   <fradet_j@epitech.net>
##
## Started on  Wed Mar 22 10:17:42 2017 Julien Fradet
## Last update Sat May 20 06:42:59 2017 Julien
##

RM	= rm -f

CC	= gcc -g

CFLAGS	= -I ./include -W -Wextra -Wall

SRCS	= src/my_minishell2.c         \
	  src/lib/my_str_to_wordtab.c \
	  src/lib/my_putchar.c        \
	  src/lib/my_putstr.c         \
	  src/lib/my_strlen.c         \
	  src/lib/get_next_line.c     \
	  src/lib/my_free_wordtab.c   \
	  src/lib/my_strncmp.c        \
	  src/lib/my_strdup.c         \
	  src/tablen.c                \
	  src/get_env.c               \
	  src/my_concat.c             \
	  src/exit_fct.c              \
	  src/lib/my_get_nbr.c        \
	  src/lib/my_strcpy.c         \
	  src/cd_fct.c                \
	  src/lib/my_show_wordtab.c   \
	  src/setenv_fct.c            \
	  src/lib/my_realloc.c        \
	  src/lib/my_unalloc.c        \
	  src/unsetenv_fct.c          \
	  src/lib/my_strcmp.c         \
	  src/my_lessconcat.c         \
	  src/lib/my_memset.c         \
	  src/check_isat.c            \
	  src/env_fct.c               \
	  src/lib/my_strcat.c         \
	  src/case_enter.c            \
	  src/fct_free.c              \
	  src/signal.c                \
	  src/crtl_c.c                \
	  src/annexe.c                \
	  src/lib/epur_str.c          \
	  src/not_builtins.c          \
	  src/count_delimitor.c       \
	  src/cd_annexe.c 	      \
	  src/redirections.c	      \
	  src/fct_delimitor.c	      \
	  src/absolute_path.c	      \
	  src/permissions.c	      \
	  src/permissions_exec.c      \
	  src/execution_classic.c

OBJS	= $(SRCS:.c=.o)

NAME	= 42sh

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
