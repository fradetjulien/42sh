/*
** my_free_wordtab.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 13:12:55 2017 Julien Fradet
** Last update Thu Apr 20 02:08:16 2017 Julien
*/

#include <stdlib.h>
#include "lib.h"

void		free_wordtab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}
