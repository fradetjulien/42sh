/*
** my_strcpy.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 22:27:17 2017 Julien Fradet
** Last update Thu Apr 20 02:06:49 2017 Julien
*/

#include <stdlib.h>
#include "lib.h"

char		*my_strcpy(char *dest, const char *src)
{
  int		i;

  i = 0;
  while (src[i] && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
