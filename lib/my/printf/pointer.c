/*
** pointer.c for  in /home/lenoir_g/PSU_2016_my_printf
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Fri Nov 18 01:15:17 2016 Guillaume LENOIR
** Last update Sat Nov 19 05:00:17 2016 Guillaume LENOIR
*/

#include <stdlib.h>
#include "my.h"

char	*init_char()
{
  char	*tab;

  if ((tab = malloc(11)) == NULL)
    return (0);
  tab[0] = 'd';
  tab[1] = 'b';
  tab[2] = 'x';
  tab[3] = 'X';
  tab[4] = 's';
  tab[5] = 'c';
  tab[6] = 'i';
  tab[7] = 'o';
  tab[8] = 'u';
  tab[9] = 'p';
  tab[10] = 0;
  return (tab);
}

flag	*init_func()
{
  flag	*tab;

  if ((tab = malloc(sizeof(flag) * 11)) == NULL)
    return (NULL);
  tab[0] = put_num;
  tab[1] = put_bin;
  tab[2] = put_unexa_min;
  tab[3] = put_unexa_up;
  tab[4] = nput_str;
  tab[5] = put_putchar;
  tab[6] = put_num;
  tab[7] = put_octal;
  tab[8] = put_dec;
  tab[9] = put_point;
  return (tab);
}
