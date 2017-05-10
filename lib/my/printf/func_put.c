/*
** func_put.c for  in /home/lenoir_g/PSU_2016_my_printf
**
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
**
** Started on  Fri Nov 18 01:39:36 2016 Guillaume LENOIR
** Last update Mar Dec 6 09:35:09 2016
*/

#include "my.h"

int		put_unexa_min(va_list list, t_prin *t)
{
  unsigned int	nb;
  int		nb2;
  char		*base;

  nb2 = va_arg(list, int);
  base = "0123456789abcdef";
  if (nb2 < 0)
    {
      put_str("ffffffff", t);
      return (0);
    }
  nb = nb2;
  put_base(t, nb, base);
}

int		put_bin(va_list list, t_prin *t)
{
  unsigned int	nb;
  char		*base;

  nb = va_arg(list, unsigned int);
  base = "01";
  put_base(t, nb, base);
}

int		put_octal(va_list list, t_prin *t)
{
  unsigned int	nb;
  char		*base;

  nb = va_arg(list, unsigned int);
  base = "01234567";
  put_base(t, nb, base);
}

int		put_dec(va_list list, t_prin *t)
{
  unsigned int	nb;
  char		*base;

  nb = va_arg(list, unsigned int);
  put_nbr(t, nb);
}

int		put_point(va_list list, t_prin *t)
{
  int	*format;
  char	*base;

  base = "0123456789abcdef";
  format = va_arg(list, void *);
  put_str("0x", t);

}
