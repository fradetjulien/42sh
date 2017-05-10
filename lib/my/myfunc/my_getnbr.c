/*
** my_getnbr.c for  in /home/lenoir_g/rendu/CPool_Day10/do_op
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Mon Oct 17 23:31:50 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:05:03 2016 benjamin boeuf
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int   c;
  long  result;

  result = 0;
  c = (str[0] == '-') ? 1 : 0;
  while (str[c])
    {
      if (str[c] >= '0' && str[c] <= '9')
        result = (result * 10) + (str[c] - '0');
      else
        {
          if (str[0] == '-')
            result *= -1;
          return ((int)result);
        }
      c++;
    }
  if (str[0] == '-')
    result *= -1;
  return ((int)result);
}

