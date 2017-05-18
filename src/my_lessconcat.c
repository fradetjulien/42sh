/*
** my_lessconcat.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Fri Mar 24 20:50:53 2017 Julien Fradet
** Last update Thu Apr 20 02:02:28 2017 Julien
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"

char		*my_lessconcat(char *str, char c)
{
  int		p;
  int		i;
  char		*path_cmd;
  int		len;

  len = my_strlen(str) + 2;
  if ((path_cmd = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  i = - 1;
  p = -1;
  while (str[++i] && str[i] != '\0')
    path_cmd[++p] = str[i];
  path_cmd[p + 1] = c;
  path_cmd[p + 2] = '\0';
  return (path_cmd);
}
