/*
** my_swap.c for  in /home/lenoir_g/rendu/d04
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Thu Oct  6 13:42:31 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:24:58 2016 benjamin boeuf
*/

#include <unistd.h>
#include "my.h"

int	print_err(char *c, int o)
{
  write(2, c, my_strlen(c));
  return (o);
}

int	is_good_int(char *c)
{
  int	i;

  i = 0;
  if (my_strlen(c) == 0)
    return (0);
  if (c[0] == '-')
    {
      if (my_strlen(c) == 1)
	return (0);
      i++;
    }
  while (c[i])
    {
      if (!(c[i] <= '9' && c[i] >= '0'))
	return (0);
      i++;
    }
  return (1);
}

int	my_swap(int *a, int *b)
{
  int	save;

  save = *a;
  *a = *b;
  *b = save;
  return (0);
}
