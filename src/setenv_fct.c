/*
** setenv_fct.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Thu Mar 23 03:15:54 2017 Julien Fradet
** Last update Sun May 21 06:26:02 2017 Julien
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "my.h"

void		display_error(char **tab, int *error)
{
  if (tab[3] != NULL)
    {
      my_putstr(tab[0]);
      my_putstr(": Too many arguments\n");
      *error = 1;
    }
  else
    {
      my_putstr(tab[0]);
      my_putstr(": Variable name must contain alphanumeric characters.\n");
    }
}

int		check_argument(char *arg, int *error)
{
  int		i;

  i = -1;
  if (arg == NULL)
    return (-1);
  while (arg && arg[++i] != '\0')
    if ((arg[i] < 48 || arg[i] > 57) &&
	(arg[i] < 65 || arg[i] > 90) &&
	(arg[i] < 97 || arg[i] > 122))
      {
	*error = 1;
	return (1);
      }
  return (0);
}

char		**replace_env(char **ev, char **tab, int i)
{
  char		*str;

  str = my_concat(tab[1], '=', tab[2]);
  my_memset(ev[i], 0, sizeof(char) * my_strlen(ev[i]));
  ev[i] = my_strdup(str);
  free(str);
  return (ev);
}

char		**annexe_setenv(char **ev, char **tab)
{
  int		i;
  int		cpt;
  char		*str;

  cpt = 0;
  i = -1;
  while (ev && ev[++i] != NULL)
    {
      if (my_strncmp(tab[1], ev[i], my_strlen(tab[1])) == 0)
	{
	  ev = replace_env(ev, tab, i);
	  cpt++;
	}
    }
  i = -1;
  if (cpt == 0)
    {
      str = my_concat(tab[1], '=', tab[2]);
      ev = my_realloc_tab(ev, 1);
      while (ev && ev[++i] != NULL);
      ev[i] = my_strdup(str);
      free(str);
    }
  return (ev);
}

int		setenv_fct(char ***ev, char **tab, char *cmd, int *error)
{
  char		*str;
  int		i;
  int		err;

  err = 0;
  if (*ev == NULL) return (84);
  if ((my_strncmp(cmd, "setenv", 6) == 0) && (i = -1))
    {
      if (tab[1] != NULL && tab[2] != NULL &&
	  tab[3] == NULL && ((err = check_argument(tab[1], error) == 0)))
	*ev = annexe_setenv(*ev, tab);
      else if (tab[1] != NULL && tab[2] == NULL &&
	       ((err = check_argument(tab[1], error) == 0)))
	{
	  str = my_lessconcat(tab[1], '=');
	  *ev = my_realloc_tab(*ev, 1);
	  while (*ev && (*ev)[++i] != NULL);
	  (*ev)[i] = my_strdup(str);
	  free(str);
	}
      else if (tab[1] == NULL) show_wordtab(*ev);
      else
	display_error(tab, error);
    }
  return (0);
}
