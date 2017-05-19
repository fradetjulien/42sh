/*
** absolute_path.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Tue May 16 14:56:30 2017 Julien
** Last update Fri May 19 15:34:01 2017 Julien
*/

#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lib.h"
#include "my.h"

int		execute_fct(char *path, char **av, char **env, int *error)
{
  int           pid;
  int           result;
  int           er;

  pid = fork();
  if (pid == 0 && path != NULL)
    {
      if ((er = execve(path, av, env)) == -1)
	{
	  my_putstr(path);
	  my_putstr(": Exec format error. Binary file not executable.\n");
	  //kill(getpid(), SIGKILL);
	  exit (1);
	  return (EXIT_FAILURE);
	}
    }
  else if (pid > 0)
    {
      if ((er = wait(&result)) == -1)
	return (EXIT_FAILURE);
    }
  else
    my_putstr("Fork fail\n");
  result = signal_check(result, error);
  return (WEXITSTATUS(result));
}

int		absolute_path(char *cmd, int *error)
{
  int		i;

  i = -1;
  if (strncmp(cmd, "/", 1) == 0)
    {
      if (permissions(cmd, error) == 0)
	return (1);
    }
  else if (strncmp(cmd, "./", 2) == 0)
    {
      if (permissions_bis(cmd, error) == 0)
	return (1);
    }
  else
    {
      while (cmd && cmd[++i] != '\0')
	{
	  if ((cmd[i] == '/') && (permissions(cmd, error) == 0) &&
	      (strncmp(cmd, "./", 2) != 0))
	    return (1);
	}
    }
  return (0);
}
