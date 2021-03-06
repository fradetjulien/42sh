/*
** my_str_to_wordtab.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 11:02:08 2017 Julien Fradet
** Last update Thu Apr 20 02:07:34 2017 Julien
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int		check(char c, char delimitor)
{
  if (c != delimitor)
    return (1);
  return (0);
}

int		count_words(char *str, char delimitor)
{
  int           i;
  int           nb_words;

  i = 0;
  nb_words = 0;
  while ((check(str[i], delimitor) == 0) && str[i] != '\0')
    i = i + 1;
  while (str[i] != '\0')
    {
      while ((check(str[i], delimitor) == 1) && str[i] != '\0')
        i = i + 1;
      nb_words++;
      while ((check(str[i], delimitor) == 0) && str[i] != '\0')
        i = i + 1;
    }
  return (nb_words);
}

int		len_str(char *str, int i, char delimitor)
{
  int           len;

  len = 0;
  while ((check(str[i], delimitor) == 0) && str[i] != '\0')
    i = i + 1;
  while ((check(str[i], delimitor) == 1) && str[i] != '\0')
    {
      len = len + 1;
      i = i + 1;
    }
  return (len);
}

char		**str_to_wordtab(char *str, char delimitor)
{
  char          **tab;
  int           i;
  int           nb_words;
  int           p;
  int           k;
  int           len;

  p = 0;
  i = 0;
  nb_words = count_words(str, delimitor);
  if ((tab = malloc(sizeof(char *) * (nb_words + 1))) == NULL)
    return (NULL);
  while (i < nb_words && (k = 0) == 0)
    {
      len = len_str(str, p, delimitor);
      if ((tab[i] = malloc(sizeof(char) * len + 1)) == NULL)
        return (NULL);
      while ((check(str[p], delimitor) == 1) && str[p] != '\0')
        tab[i][k++] = str[p++];
      tab[i++][k] = '\0';
      p = p + 1;
    }
  tab[i] = NULL;
  return (tab);
}
