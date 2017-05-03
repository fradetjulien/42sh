/*
** get_next_line.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 13:34:56 2017 Julien Fradet
** Last update Thu Apr 20 02:11:50 2017 Julien
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "lib.h"

int	select_c(const int fd, char *str)
{
  static char	buffer[READ_SIZE];
  static int	nbr = READ_SIZE;
  static int	i = 0;

  if (i >= nbr || i == 0)
    {
      i = 0;
      if ((nbr = read(fd, buffer, READ_SIZE)) <= 0)
	return (0);
    }
  if (nbr == 0)
    {
      *str = '\0';
      i = -1;
    }
  else
    if (buffer[i] == '\n')
      *str = '\0';
    else
      {
	*str = buffer[i];
	*(str + 1) = 0;
      }
  i++;
  return (nbr);
}

char	*my_realloc(char *old, int size)
{
  char	*new;
  int	i;

  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(old) + size))) == NULL)
    return (NULL);
  while (old[i] != '\0')
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  new[i] = 0;
  return (new);
}

char	*get_next_line(const int fd)
{
  char	*str;
  int	nbr;
  int	i;

  nbr = 1;
  i = 0;
  if ((str = malloc((READ_SIZE + 1) * sizeof(*str))) == NULL)
    return (NULL);
  nbr = select_c(fd, &str[i]);
  if (nbr == 0)
    {
      free(str);
      return (NULL);
    }
  while (str[i])
    {
      if (i % READ_SIZE == 0)
	if ((str = my_realloc(str, i + READ_SIZE + 1)) == NULL)
	  return (NULL);
      nbr = select_c(fd, &str[++i]);
    }
  str[++i] = '\0';
  return (str);
}
