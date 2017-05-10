/*
** my_str_isalpha.c for  in /home/lenoir_g/rendu/CPool_Day06
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Tue Oct 11 20:16:07 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:13:09 2016 benjamin boeuf
*/

#include "my.h"

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] == 127)
	return (0);
      i++;
    }
  return (1);
}
