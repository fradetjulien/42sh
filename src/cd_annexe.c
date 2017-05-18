/*
** cd_annexe.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Sun Apr  9 13:43:11 2017 Julien Fradet
** Last update Thu Apr 20 01:59:36 2017 Julien
*/

#include <unistd.h>
#include "lib.h"
#include "my.h"

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
      *ev = get_pwd(*ev);
    }
  return (0);
}
