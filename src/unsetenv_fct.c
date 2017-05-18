/*
** unsetenv_fct.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Thu Mar 23 21:02:19 2017 Julien Fradet
** Last update Thu Apr 20 02:03:48 2017 Julien
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"

int		unsetenv_fct(char ***ev, char **tab, char *cmd)
{
  char		*str;
  int		i;
  int		cpt;

  i = -1;
  cpt = 0;
  if (my_strncmp(cmd, "unsetenv", 8) == 0)
    {
      if (tab[1] != NULL)
	{
	  str = my_strdup(tab[1]);
	  while (*ev && (*ev)[++i] != NULL)
	    if (my_strncmp(str, (*ev)[i], my_strlen(str)) == 0)
	      cpt = cpt + 1;
	  if (cpt == 1)
	    *ev = my_unalloc_tab(*ev, str);
	  free(str);
	}
    }
  return (0);
}
