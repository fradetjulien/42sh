/*
** my_putchar.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 11:51:38 2017 Julien Fradet
** Last update Thu Apr 20 02:08:40 2017 Julien
*/

#include <unistd.h>
#include "lib.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
