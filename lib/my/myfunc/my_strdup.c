/*
** my_strdup.c for  in /home/lenoir_g/Lib
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Tue Oct 18 10:51:14 2016 Guillaume LENOIR
** Last update Wed Dec 14 04:03:39 2016 LENOIR
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  if ((ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
