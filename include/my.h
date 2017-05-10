/*
** my.h for  in /home/lenoir_g/rendu/CPool_Day09
**
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
**
** Started on  Fri Oct 14 17:34:43 2016 Guillaume LENOIR
** Last update Fri Mar 10 00:20:20 2017 LENOIR
*/

#ifndef		__MY_H__
#define		__MY_H__

#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char);
int	my_isneg(int);
int	put_error(char *);
char	**create_chartab(int, int);
char	*my_strdup(char *);
int	my_is_digit(char *);
int	my_put_nbr(int);
int	m_is_prime(int);
int	my_swap(int *, int *);
int	my_rand(int, int);
char	*my_strlcat(char *, char *);
char	*fill_with_carac(char *, char, int);
int	index_final_char(char *, char);
int	count_char(char *, char);
int	my_putstr(char *);
int	my_getnbr(char *);
void	my_sort_int_tab(int *, int);
int	my_power_rec(int, int);
int	my_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, int);
char	*my_revstr(char *);
char	*my_strstr(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
int	stlen(int);
int	ma_strlen(int);
int	my_str_isalpha(char *);
int	my_str_isnum(char *);
int	my_str_islower(char *);
int	my_str_isupper(char *);
int	my_str_isprintable(char *);
int	my_showstr(char *);
int	my_showmem(char *, int);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
int	my_strlen(char *);
char	**my_str_to_wordtab(char *, char);

#endif

#ifndef PRINTF_H_
# define PRINTF_H_

#include <stdarg.h>

typedef	struct	s_prin
{
  char		c;
  struct s_prin	*next;
}		t_prin;

typedef int(*flag)(va_list, t_prin *);

typedef	struct	s_fla
{
  va_list	ap;
  char		*tab;
  flag		*fl;
}		t_fla;

int     put_num(va_list, t_prin *);
int     put_bin(va_list, t_prin *);
int     put_unexa_min(va_list, t_prin *);
int     put_unexa_up(va_list, t_prin *);
int     nput_str(va_list, t_prin *);
int     put_putchar(va_list, t_prin *);
int     put_num(va_list, t_prin *);
int     put_octal(va_list, t_prin *);
int     put_stroctal(va_list, t_prin *);
int     put_dec(va_list, t_prin *);
int     put_point(va_list, t_prin *);
char	*init_char();
flag	*init_func();
t_prin	*add_char(char, t_prin *);
int	my_printf(char *, ...);
int     use_flag(char *s, int i, t_fla *p, t_prin *e);
t_prin  *init_print(char *s);
void    put_base(t_prin *t, int nb, char *base);
int     put_nbr(t_prin *t, int nb);
void    put_str(char *s, t_prin *t);
char		*get_next_line(const int fd);

#endif	/* !PRINTF_H_ */
