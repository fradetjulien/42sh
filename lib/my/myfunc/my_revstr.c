/*
** my_revstr.c for  in /home/lenoir_g/rendu/CPool_Day06
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Tue Oct 11 19:37:24 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:20:00 2016 benjamin boeuf
*/

#include "my.h"
/*
int	ma_strlen(char *src)
{
  int	i;

  i = 0;
  while (src[i])
    i++;
  return (i);
}
*/
char	*my_revstr(char *src)
{
  int   i;
  char  *tmp1;
  char  *tmp2;
  int   tmp3;

  i = my_strlen(src);
  tmp1 = src;
  tmp2 = tmp1 + (i - 1);
  while (tmp2 > tmp1)
    {
      tmp3 = *tmp1;
      *tmp1 = *tmp2;
      *tmp2 = tmp3;
      tmp1 = tmp1 + 1;
      tmp2 = tmp2 - 1;
    }
  return (src);
}
