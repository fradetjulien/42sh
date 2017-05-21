/*
** loop.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sun May 21 05:24:48 2017 Julien
** Last update Sun May 21 06:20:08 2017 Julien
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "lib.h"
#include "my.h"

int		loop(char **av, char **env, char **ev, int er)
{
  char          **tab;
  char		*cmd;
  char		*chemin;
  int		i;

  i = 0;
  while ((cmd = get_next_line(0)))
    {
      if ((er = count_delimitor(&cmd) != 0)) return (0);
      if (case_enter(cmd) == 0)
	{
	  if (((a_path(cmd, &er)) == 1) && (n_bu(tab = str_to_wordtab(cmd, ' ')) == 0))
	    check_execution_bin(cmd, av, env, &er);
	  else
	    {
	      tab = str_to_wordtab(cmd, ' '); builtins_fct(&ev, tab, cmd, &er);
	      if ((chemin = my_access(tab, get_env(env, "PATH="))) != NULL)
		execute(chemin, tab, env, &er);
	      else if (er != 1) if ((i = n_bu(tab)) == 0) print_err(tab, &er);
	    }
	  if (annexe(cmd, ev) != 1) check_isat();
	}
    }
  return (er);
}
