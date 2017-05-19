/*
** my_concat.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 16:57:53 2017 Julien Fradet
** Last update Fri May 19 17:29:45 2017 Julien
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"

char		*my_concat(char	*str, char c, char *sec_str)
{
  int		p;
  int		i;
  char		*path_cmd;
  int		len;

  if (str == NULL || sec_str == NULL)
    return (NULL);
  len = (my_strlen(str)) + (my_strlen(sec_str)) + 2;
  if ((path_cmd = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  i = -1;
  p = 0;
  while (str[++i] && str[i] != '\0')
    path_cmd[p++] = str[i];
  path_cmd[p] = c;
  i = -1;
  p = p + 1;
  while (sec_str[++i] && sec_str[i] != '\0')
    path_cmd[p++] = sec_str[i];
  path_cmd[p] = '\0';
  return (path_cmd);
}
