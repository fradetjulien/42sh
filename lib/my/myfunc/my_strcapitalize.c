/*
** my_strcapitalize.c for  in /home/lenoir_g/rendu/CPool_Day06
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Tue Oct 11 09:12:26 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:10:56 2016 benjamin boeuf
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 1;
  if (str[0] >= 97 && str[0] <= 122)
    str[0] = str[0] - 32;
  while (str[i] != '\0')
    {
      if (str[i - 1] >= 23 && str[i - 1] <= 47 || str[i - 1] == ';')
	{
	  if (str[i] <= 'z' && str[i] >= 'a')
	    str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
