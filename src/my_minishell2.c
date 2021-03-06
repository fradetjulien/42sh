/*
** my_minishell2.c for  in /home/fradet_j/PSU/PSU_2016_minishell2
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 10:12:33 2017 Julien Fradet
** Last update Sun May 21 10:07:18 2017 Julien
*/

#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "lib.h"
#include "my.h"

int		builtins_fct(char ***ev, char **tab, char *cmd, int *error)
{
  int		err;

  err = 0;
  if (annexe(cmd, *ev) == 1)
    return (1);
  exit_fct(tab[0], tab, error);
  if ((err = cd_fct(tab[0], tab, ev, error)) == 1)
    {
      my_putstr(tab[1]); my_putstr(": Not a directory.\n");
      *error = 1;
    }
  setenv_fct(ev, tab, cmd, error);
  unsetenv_fct(ev, tab, cmd);
  echo(tab);
  where(tab, *ev, error);
  which(tab, *ev, error);
  return (0);
}

char		**create_env(char **env)
{
  char		**ret;
  int		len;
  int		i;

  i = -1;
  if (env[0] == NULL)
    return (NULL);
  len = tablen(env) + 1;
  if ((ret = malloc(sizeof(char *) * len)) == NULL)
    return (NULL);
  while (++i < len)
    {
      if ((ret[i] = malloc(sizeof(char) * len)) == NULL)
	return (NULL);
      my_memset(ret[i], 0, sizeof(char) * len);
    }
  len = -1;
  while (env[++len] != NULL)
    ret[len] = my_strdup(env[len]);
  ret[len] = NULL;
  return (ret);
}

char		*my_access(char **cmd, char *path)
{
  char		**tab;
  char		*cat;
  int		i;

  i = -1;
  if (path == NULL)
    return (NULL);
  path = path + 5;
  if (strcmp(path, "/") == 0)
    return (NULL);
  tab = str_to_wordtab(path, ':');
  while (tab[++i] != NULL)
    {
      if (strncmp(cmd[0], "./", 2) == 0)
	return (NULL);
      else
	cat = my_concat(tab[i], '/', cmd[0]);
      if ((access(cat, F_OK) == 0) && (access(cat, X_OK) == 0))
	return (cat);
    }
  return (NULL);
}

int		execute(char *path, char **av, char **env, int *error)
{
  int		pid;
  int		result;
  int		er;

  pid = fork();
  if (pid == 0 && path != NULL)
    {
      if ((er = execve(path, av, env)) == -1)
	{
	  my_putstr("Permission denied\n");
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

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  char		**ev;
  int		er;

  er = 0;
  if ((ev = create_env(env)) == NULL) return (84);
  signal(SIGINT, affi); check_isat();
  return (loop(av, env, ev, er));
  return (0);
}
