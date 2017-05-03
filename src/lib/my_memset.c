/*
** my_memset.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Fri Mar 24 22:53:59 2017 Julien Fradet
** Last update Thu Apr 20 02:08:30 2017 Julien
*/

#include "lib.h"

void		*my_memset(char *buf, int nb, int size)
{
  int		i;

  i = -1;
  while (buf && ++i < size)
    buf[i] = nb;
  return (buf);
}
