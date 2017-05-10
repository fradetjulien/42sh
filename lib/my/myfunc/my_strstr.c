/*
** my_strcmp.c for  in /home/lenoir_g/rendu/CPool_Day06
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Mon Oct 10 15:53:41 2016 Guillaume LENOIR
** Last update Fri Apr  7 22:52:49 2017 LENOIR
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  if (str[0])
    {
      i = 0;
      while (to_find[i])
	{
	  if (to_find[i] != str[i])
	    return (my_strstr(str + 1, to_find));
	  i++;
	}
      return (str);
    }
  else
    return (NULL);
}
