/*
** my_square_root.c for  in /home/lenoir_g/rendu/CPool_Day05
**
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
**
** Started on  Mon Oct 10 12:01:46 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:10:33 2016 benjamin boeuf
*/

#include "my.h"

int	my_square_root(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    return (0);
  while (i < nb )
    {
      if ((i * i) == nb)
	return (i);
      i++;
    }
  return (0);
}
