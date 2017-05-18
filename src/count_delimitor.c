/*
** count_delimitor.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Sat Apr  8 23:00:01 2017 Julien Fradet
** Last update Sat Apr  8 23:01:53 2017 Julien Fradet
*/

#include "my.h"

int		count_delimitor(char *cmd)
{
  int		i;
  int		cpt;

  cpt = 0;
  i = -1;
  while (cmd && cmd[++i] != '\0')
    {
      if (cmd[i] == '|' || cmd[i] == ';' ||
	  cmd[i] == '>' || cmd[i] == '<')
	cpt = cpt + 1;
    }
  return (cpt);
}
