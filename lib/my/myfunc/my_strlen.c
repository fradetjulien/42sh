/*
** my_strlen.c for  in /home/lenoir_g/rendu/d04
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Thu Oct  6 13:47:12 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:13:39 2016 benjamin boeuf
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
