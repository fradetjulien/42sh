/*
** my_power_it.c for  in /home/lenoir_g/rendu/CPool_Day05
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Mon Oct 10 11:42:27 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:06:27 2016 benjamin boeuf
*/

#include "my.h"

int	my_power_rec(int nb, int p)
{
  if (p < 0)
    return (0);
  if (p == 0)
    return (1);
  if (p == 1)
    return (nb);
  else
    return (nb * my_power_rec(nb, p - 1));
}
