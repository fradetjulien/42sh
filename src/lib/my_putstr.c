/*
** my_putstr.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 11:51:56 2017 Julien Fradet
** Last update Thu Apr 20 02:05:38 2017 Julien
*/

#include "lib.h"

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str && str[i] && str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
