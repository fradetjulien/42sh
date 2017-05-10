/*
** put_nbr.c for  in /home/lenoir_g/PSU_2016_my_printf
**
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
**
** Started on  Fri Nov 18 01:24:49 2016 Guillaume LENOIR
** Last update Mar Dec 6 09:35:05 2016
*/

#include "my.h"

void	put_base(t_prin *t, int nb, char *base)
{
  int	result;
  int	diviseur;
  int	size_base;

  size_base = my_strlen(base);
  if (nb < 0)
    {
      t = add_char('-', t);
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      t = add_char(base[result], t);
      diviseur = diviseur / size_base;
    }
}

int	put_nbr(t_prin *t, int nb)
{
  int	mod;

  if (nb < 0)
    {
      t = add_char('-', t);
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
          nb = (nb - mod) / 10;
	  put_nbr(t, nb);
	  t = add_char(48 + mod, t);
        }
      else
        t = add_char(48 + nb % 10, t);
    }
}

void	put_str(char *s, t_prin *t)
{
  int	i;

  i = 0;
  while (s[i])
    {
      t = add_char(s[i], t);
      i++;
    }
}
