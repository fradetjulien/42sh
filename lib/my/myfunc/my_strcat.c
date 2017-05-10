/*
** my_strcat.c for  in /home/lenoir_g/rendu/CPool_Day07/lib/my
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Wed Oct 12 10:49:29 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:11:14 2016 benjamin boeuf
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] != '\0')
    {
    dest[i] = src[j];
    i = i + 1;
    j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}

