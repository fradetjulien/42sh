/*
** tablen.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 16:04:39 2017 Julien Fradet
** Last update Wed Mar 22 16:06:39 2017 Julien Fradet
*/

#include <unistd.h>
#include "my.h"

int		tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    i = i + 1;
  return (i);
}
