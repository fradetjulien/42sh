/*
** not_builtins.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Fri Apr  7 22:24:40 2017 Julien Fradet
** Last update Thu Apr 20 02:03:02 2017 Julien
*/

#include "lib.h"
#include "my.h"

void		print_error(char **cmd, int *error)
{
  my_putstr(cmd[0]);
  my_putstr(": Command not found.\n");
  *error = 1;
}

int		not_builtins(char **cmd)
{
  if ((my_strcmp(cmd[0], "cd") == 0) ||
      (my_strcmp(cmd[0], "setenv") == 0))
    return (1);
  if ((my_strcmp(cmd[0], "unsetenv") == 0) ||
      (my_strcmp(cmd[0], "exit") == 0))
    return (1);
  if (my_strcmp(cmd[0], "env") == 0)
    return (1);
  return (0);
}