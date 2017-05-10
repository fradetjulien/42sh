/*
** my_isneg.c for  in /home/lenoir_g/rendu/CPool_Day03
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Wed Oct  5 10:00:27 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:05:36 2016 benjamin boeuf
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
