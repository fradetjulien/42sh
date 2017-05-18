/*
** env_fct.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Fri Mar 24 23:25:06 2017 Julien Fradet
** Last update Thu Apr 20 02:01:00 2017 Julien
*/

#include "lib.h"
#include "my.h"

void		env_fct(char **ev)
{
  show_wordtab(ev);
  check_isat();
}
