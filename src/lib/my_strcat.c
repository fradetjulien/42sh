/*
** my_strcat.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 13:13:32 2017 Julien Fradet
** Last update Thu Apr 20 02:06:27 2017 Julien
*/

#include "lib.h"

char		*my_strcat(char *dest, const char *src)
{
  int		i;
  int		p;

  p = 0;
  i = my_strlen(dest);
  while (src[p] && src[p] != '\0')
    {
      dest[i] = src[p];
      p = p + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
