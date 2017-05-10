/*
** my_putstr.c for  in /home/lenoir_g/rendu/d04
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Thu Oct  6 13:48:51 2016 Guillaume LENOIR
** Last update Wed Mar  8 16:40:29 2017 LENOIR
*/

#include "my.h"
#include <time.h>
#include <stdlib.h>

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_rand(int min, int max)
{
  static int	first = 0;

  if (first == 0)
    {
      srand (time (NULL));
      first = 1;
    }
  return (rand () % (max - min) + min);
}
