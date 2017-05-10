/*
** my_is_prime.c for  in /home/lenoir_g/rendu/CPool_Day05
** 
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
** 
** Started on  Mon Oct 10 12:08:24 2016 Guillaume LENOIR
** Last update Fri Oct 28 21:06:10 2016 benjamin boeuf
*/

#include "my.h"

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  while (i < nb)
    {
      if (nb % i == 0)
	return (0);
      i++;
    }
  return (1);
}
