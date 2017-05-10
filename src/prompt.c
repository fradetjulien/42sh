/*
** prompt.c for  in /home/lenoir/rendu/PSU_2015_minishell2
**
** Made by lenoir_g
** Login   <guillaume.lenoir@epitech.net>
**
** Started on  Thu Mar 24 00:02:42 2016 lenoir_g
** Last update Fri Apr  7 06:59:07 2017 LENOIR
*/

#include "mysh.h"

int	my_exit(int nb)
{
  my_printf("exit\n");
  exit(nb);
  return (SUCCES);
}

int	draw_prompt(t_sh *sh)
{
  my_printf("%s ~ %d >> ", get_env_var(sh->env_list, "USER"), sh->count);
  return (SUCCES);
}
