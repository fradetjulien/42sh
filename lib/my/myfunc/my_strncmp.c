/*
** my_strcmp.c for  in /home/lenoir_g/rendu/CPool_Day06
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Mon Oct 10 15:53:41 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:14:27 2016 benjamin boeuf
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
    i++;
  if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
    return (0);
  else if (s1[i] > s2[i])
    return (1);
  else
    return (-1);
}
