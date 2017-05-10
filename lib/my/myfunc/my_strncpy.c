/*
** my_strcpy.c for  in /home/lenoir_g/rendu/CPool_Day06
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Mon Oct 10 14:08:52 2016 Guillaume LENOIR
** Last update Fri Mar 10 01:40:16 2017 LENOIR
*/

#include "my.h"

char	*my_strncpy(char *src, int n)
{
  int	i;
  char	*ret;

  if ((ret = malloc(n + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i] && i < n)
    {
      ret[i] = src[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

int	my_is_digit(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

char	*my_strlcat(char *a, char *b)
{
  int	i;
  int	j;
  char	*ret;
  
  i = j = 0;
  if ((ret = malloc(my_strlen(a) + my_strlen(b) + 1)) == NULL)
    return (NULL);
  while (a[i])
    {
      ret[j] = a[i];
      j++;
      i++;
    }
  i = 0;
  while (b[i])
    {
      ret[j] = b[i];
      j++;
      i++;
    }
  ret[j] = 0;
  return (ret);
}
