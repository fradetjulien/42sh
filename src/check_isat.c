/*
** check_isat.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Fri Mar 24 23:36:07 2017 Julien Fradet
** Last update Thu Apr 20 02:13:03 2017 Julien
*/

#include <unistd.h>
#include "lib.h"
#include "my.h"

void		check_isat()
{
  if (isatty(0) == 1)
    my_putstr("$>");
}
