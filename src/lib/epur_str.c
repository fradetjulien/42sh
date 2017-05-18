/*
** epur_str.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Thu Apr  6 20:20:06 2017 Julien Fradet
** Last update Thu Apr 20 02:07:45 2017 Julien
*/

#include <unistd.h>
#include "lib.h"

char	*epur_str(char *old)
{
  char	*new;
  int	i;
  int	j;

  i = -1;
  j = 0;
  if (old[0] == '\0') return (old);
  new = my_strdup(old);
  while (old && old[++i])
    {
      if (old[i] != ' ' && old[i] != '\t')
	{
	  new[j] = old[i];
	  j++;
	  if (old[i + 1] == ' ' || old[i + 1] == '\t')
	    {
	      new[j] = ' ';
	      j++;
	    }
	}
    }
  new[j] = '\0';
  if (new[j - 1] == ' ')
    new[j - 1] = '\0';
  return (new);
}
