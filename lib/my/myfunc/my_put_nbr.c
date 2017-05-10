/*
** my_put_nbr.c for  in /home/lenoir_g/rendu/CPool_Day03
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Wed Oct  5 15:45:25 2016 Guillaume LENOIR
** Last update Fri Feb 10 05:08:11 2017 LENOIR
*/

#include "my.h"

int	count_char(char *s, char t)
{
  int	i;
  int	c;

  i = c = 0;
  while (s[i])
    {
      if (s[i] == t)
	c++;
      i++;
    }
  return (c);
}

int	my_put_nbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
          nb = (nb - mod) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nb % 10);
    }
}
