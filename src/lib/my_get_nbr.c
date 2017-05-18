/*
** my_get_nbr.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src/lib
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 20:05:38 2017 Julien Fradet
** Last update Thu Apr 20 02:08:23 2017 Julien
*/

#include "lib.h"

int		my_getnbr(const char *nbr)
{
  int		i;
  int		nb;

  i = 0;
  if (nbr[i] == '-')
    i = i + 1;
  nb = nbr[i] - 48;
  i = i + 1;
  while (nbr[i] != '\0')
    {
      nb = (nb * 10) + (nbr[i] - 48);
      i = i + 1;
    }
  i = 0;
  if (nbr[i] == '-')
    nb = nb * (-1);
  return (nb);
}
