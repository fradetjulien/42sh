/*
** my_strcmp.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Fri Mar 24 20:42:13 2017 Julien Fradet
** Last update Thu Apr 20 02:06:37 2017 Julien
*/

#include <unistd.h>
#include "lib.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;
  int		res;

  res = 0;
  i = 0;
  while (s1 && s2 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    i = i + 1;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  res = s2[i] - s1[i];
  return (res);
}
