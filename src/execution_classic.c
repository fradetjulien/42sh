/*
** execution_classic.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sat May 20 05:12:47 2017 Julien
** Last update Sat May 20 06:35:12 2017 Julien
*/

#include <unistd.h>
#include "lib.h"
#include "my.h"

int		execution_classique(char **tab, char *cmd, char **env, int *error)
{
  char		*chemin;

  tab = str_to_wordtab(cmd, ' ');
  if ((chemin = my_access(tab, get_env(env, "PATH="))) != NULL)
    execute(chemin, tab, env, error);
  return (0);
}
