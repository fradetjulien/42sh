/*
** cd_annexe.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Sun Apr  9 13:43:11 2017 Julien Fradet
** Last update Sun May 21 00:55:24 2017 Julien
*/

#include <unistd.h>
#include <string.h>
#include "lib.h"
#include "my.h"

int		similary_pwd(char *old_pwd, char *pwd)
{
  if (my_strcmp(old_pwd, pwd) == 0)
    return (1);
  return (0);
}

int		cd_tiret(char ***ev, char *old_pwd, int *error)
{
  int		i;
  int		cpt;
  char		*pwd;
  int		p;

  p = -1;
  cpt = 0;
  i = -1;
  while (*ev && (*ev)[++i] != NULL)
    if (my_strncmp("OLDPWD", (*ev)[i], 6) == 0)
      cpt++;
  if (cpt == 0)
    *error = 1;
  else
    {
      old_pwd = get_oldpwd(*ev);
      while (*ev &&
	     (my_strncmp((*ev)[++p], "OLDPWD", my_strlen("OLDPWD"))) != 0);
      pwd = my_strdup((*ev)[p]);
      pwd = pwd + 7;
      *ev = path_oldpwd(*ev, old_pwd);
      if ((chdir(pwd)) == -1) return (1);
      *ev = get_pwd(*ev); return (similary_pwd(old_pwd, pwd));
    }
  return (0);
}

char		*get_path_home(char **ev)
{
  char		*path;
  int		i;
  int		statut;

  statut = 0;
  i = -1;
  path = NULL;
  while (ev && ev[++i] != NULL)
    {
      if (strncmp(ev[i], "HOME", my_strlen("HOME")) == 0)
	{
	  path = my_strdup(ev[i]);
	  path = path + 5;
	  statut = 1;
	}
    }
  if (statut == 0)
    return (NULL);
  return (path);
}

int		cd_alone(char **ev)
{
  char		*pwd;
  char		*path;

  pwd = NULL;
  if ((path = get_path_home(ev)) == NULL)
    return (1);
  if ((pwd = get_oldpwd(ev)) == NULL)
    return (1);
  if ((ev = path_oldpwd(ev, pwd)) == NULL)
    return (1);
  if (chdir(path) == -1)
    return (1);
  if ((ev = get_pwd(ev)) == NULL)
    return (1);
  return (0);
}
