/*
** my_strcmp.c for  in /home/lenoir_g/rendu/CPool_Day06
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Mon Oct 10 15:53:41 2016 Guillaume LENOIR
** Last update Fri Mar 10 00:27:25 2017 LENOIR
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
