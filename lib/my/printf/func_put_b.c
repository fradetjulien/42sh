/*
** func_put_b.c for  in /home/lenoir_g/PSU_2016_my_printf
**
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
**
** Started on  Fri Nov 18 01:54:16 2016 Guillaume LENOIR
** Last update Mar Dec 6 09:33:43 2016
*/

#include "my.h"

int		nput_str(va_list list, t_prin *t)
{
  char		*format;

  format = va_arg(list, char *);
  put_str(format, t);
}

int		put_putchar(va_list list, t_prin *t)
{
  char		c;

  c = va_arg(list, int);
  t = add_char(c, t);
}

int		put_num(va_list list, t_prin *t)
{
  int		nb;

  nb = va_arg(list, int);
  put_nbr(t, nb);
}

int		put_unexa_up(va_list list, t_prin *t)
{
  int		nb;
  unsigned int	nb2;
  char		*base;

  nb = va_arg(list, int);
  base = "0123456789ABCDEF";
  if (nb < 0)
    {
      put_str("FFFFFFFF", t);
      return (0);
    }
  nb2 = nb;
  put_base(t, nb2, base);
}
