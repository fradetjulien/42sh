/*
** my_strlen.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 11:52:16 2017 Julien Fradet
** Last update Thu Apr 20 02:07:17 2017 Julien
*/

#include "lib.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i] && str[i] != '\0')
    i++;
  return (i);
}
