/*
** my_realloc.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Thu Mar 23 03:37:56 2017 Julien Fradet
** Last update Thu Apr 20 02:08:54 2017 Julien
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

char		**my_realloc_tab(char **tab, int add_lines)
{
  char		**new_tab;
  int		act_lines;
  int		j;

  act_lines = -1;
  while (tab && tab[++act_lines] != NULL);
  if ((new_tab = malloc(sizeof(char *) * (act_lines + add_lines + 1))) == NULL)
    return (NULL);
  new_tab[act_lines + add_lines] = NULL;
  j = -1;
  while (++j < act_lines)
    new_tab[j] = tab[j];
  free(tab);
  while (j < act_lines + add_lines)
    new_tab[j++] = NULL;
  return (new_tab);
}
