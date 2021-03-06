/*
** loop.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sun May 21 05:24:48 2017 Julien
** Last update Sun May 21 12:00:26 2017 Julien
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

  while ((cmd = get_next_line(0)))
    {
      if ((er = count_delimitor(&cmd) == 1)) return (0);
      if (case_enter(cmd) == 0)
	{
	  if (((a_path(cmd, &er)) == 1) && (n_bu(tab = str_to_wordtab(cmd, ' ')) == 0))
	    check_execution_bin(cmd, av, env, &er);
	  else
	    {
	      if ((tab = str_to_wordtab(cmd, ' ')) == NULL) return (84);
	      builtins_fct(&ev, tab, cmd, &er);
	      repeat(tab, ev, av, &er);
	      if (((chemin = my_access(tab, get_env(env, "PATH="))) != NULL) &&
		  n_bu(tab) == 0)
		execute(chemin, tab, env, &er);
	      else if (er != 1) if (n_bu(tab) == 0) print_err(tab, &er);
	    }
	  if (annexe(cmd, ev) != 1) check_isat();
	}
    }
  return (er);
}
