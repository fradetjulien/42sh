/*
** my_unalloc.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Thu Mar 23 22:29:18 2017 Julien Fradet
** Last update Thu Apr 20 02:07:40 2017 Julien
*/

#include <stdlib.h>
#include "lib.h"

char		**my_unalloc_tab(char **tab, char *str)
{
  char		**new_tab;
  int		lines;
  int		i;
  int		p;

  p = 0;
  lines = -1;
  i = -1;
  while (tab && tab[++lines] != NULL);
  if ((new_tab = malloc(sizeof(char *) * lines)) == NULL)
    return (NULL);
  new_tab[lines - 1] = NULL;
  while (++i < lines - 1)
    {
      if (my_strncmp(tab[p], str, my_strlen(str)) == 0)
	p++;
      if ((new_tab[i] = my_strdup(tab[p])) == NULL)
	return (NULL);
      p++;
    }
  free(tab);
  return (new_tab);
}
