/*
** permissions_exec.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sat May 20 04:59:48 2017 Julien
** Last update Sat May 20 05:57:31 2017 Julien
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

int		check_execution_bin(char *cmd, char **av, char **env, int *error)
{
  if (execute_fct(cmd, av, env, error) == EXIT_FAILURE)
    *error = 1;
  return (0);
}

int		permissions_exec(char *cmd, char **tab, int *error)
{
  int		statut;

  statut = 0;
  if (((statut = absolute_path(cmd, error)) == 1) &&
      ((statut = not_builtins(tab = str_to_wordtab(cmd, ' '))) == 0))
    return (1);
  return (0);
}

int		permissions_exec_clas(char *cmd, char **tab, int *error)
{
  int		statut;

  statut = 0;
  if (((statut = absolute_path(cmd, error)) == 0) &&
      ((statut = not_builtins(tab = str_to_wordtab(cmd, ' '))) == 0))
      return (1);
  return (0);
}
