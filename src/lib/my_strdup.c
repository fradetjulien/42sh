/*
** my_strdup.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 15:51:01 2017 Julien Fradet
** Last update Thu Apr 20 02:07:03 2017 Julien
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char		*my_strdup(char *str)
{
  char		*new_str;
  int		i;
  int		len;

  len = my_strlen(str) + 1;
  i = 0;
  if ((new_str = malloc(sizeof(char *) * len)) == NULL)
    return (NULL);
  while (str && str[i] && str[i] != '\0')
    {
      new_str[i] = str[i];
      i = i + 1;
    }
  new_str[i] = '\0';
  return (new_str);
}
