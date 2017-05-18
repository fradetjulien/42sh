/*
** my_strncmp.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 13:15:55 2017 Julien Fradet
** Last update Tue May  9 18:43:29 2017 Julien
*/

#include "lib.h"

int		my_strncmp(char *s1, char *compare, int len)
{
  int		i;
  int		res;

  res = 0;
  i = 0;
  while (s1 && compare && s1[i] && compare[i] && i <= len && res == 0)
    {
      res = compare[i] - s1[i];
      if (res == 0)
	i = i + 1;
    }
  if (res < 0 || i != len)
    return (1);
  if (res > 0 || i != len)
    return (-1);
  return (0);
}
