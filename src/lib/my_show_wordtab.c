/*
** my_show_wordtab.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Thu Mar 23 03:11:44 2017 Julien Fradet
** Last update Thu Apr 20 02:06:12 2017 Julien
*/

#include <unistd.h>
#include "lib.h"

char		*show_wordtab(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL)
    return (NULL);
  while (tab && tab[i] && tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (NULL);
}
