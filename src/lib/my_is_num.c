/*
** my_is_num.c for  in /home/julien/PSU/repo_robin/my/src/lib
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sun May 21 10:46:51 2017 Julien
** Last update Sun May 21 10:46:59 2017 Julien
*/

#include <unistd.h>
#include "lib.h"

int	my_is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}
