##
## Makefile for  in /home/lenoir_g/CPool_rush2
##
## Made by Guillaume LENOIR
## Login   <lenoir_g@epitech.net>
##
## Started on  Sat Oct 15 14:52:46 2016 Guillaume LENOIR
## Last update Wed Feb 15 23:09:27 2017 LENOIR
##

SRC	= 	my_find_prime_sup.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_strdup.c		\
		my_power_rec.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_sort_int_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\
		get_next_line.c

PRINT = func_put_b.c	\
				func_put.c	\
				my_printf.c	\
				pointer.c	\
				put_nbr.c

OBJ	= $(addprefix myfunc/, $(SRC:.c=.o)) $(addprefix printf/, $(PRINT:.c=.o))

RM 	= rm -f

CFLAGS	= -I../../include/ -g

NAME	= libmy.a

$(NAME): $(OBJ)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
