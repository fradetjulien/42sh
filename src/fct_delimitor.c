/*
** fct_delimitor.c for  in /home/julien/PSU/PSU_2016_42sh/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Tue May  9 18:50:43 2017 Julien
** Last update Thu May 18 06:22:47 2017 Julien
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "lib.h"
#include "my.h"

/*int		pype(char **tab, char ***ev ,int nb_deli, char *cmd, char **env)
{
  int		fd[2];
  int		status;
  pid_t		pid;
  int		i;
  int		done;
  int		error;
  char		*chemin;

  error = 0;
  done = 0;
  i = 0;
  if (pipe(fd) == -1)
    return (-1);
  while (done != -1)
    {
      if ((pid = fork()) == -1)
	return (-1);
      if (pid == 0)
	{
	  if (i < nb_deli)
	    dup2(fd[1], 1);
	  if (i != 0)
	    dup2(fd[0], 0);
	  if (i == nb_deli)
	    {
	      close(fd[0]);
	      close(fd[1]);
	    }
	  builtins_fct(ev, tab, cmd, &nb_deli);
	  if ((chemin = my_access(tab, get_env(env, "PATH="))) != NULL)
	    execute(chemin, tab, env, &error);
	  if (i < nb_deli)
	    i++;
	  else
	    {
	      wait(&status);
	      close(fd[0]);
	      close(fd[1]);
	      done = 1;
	    }
	}
    }
  return (0);
  }*/

int		fct_delimitor(char *cmd)
{
  char		**tab;

  if ((tab = str_to_wordtab(cmd, '|')) == NULL)
    return (-1);
  //pype(tab, ev, nb_deli, cmd, env);
  return (0);
}
