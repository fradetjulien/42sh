/*
** count_delimitor.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Sat Apr  8 23:00:01 2017 Julien Fradet
** Last update Sun May 21 04:33:48 2017 Julien
*/

#include "lib.h"
#include "my.h"

int		count_delimitor(char **cmd)
{
  int		i;
  int		cpt;

  cpt = 0;
  i = -1;
  while (cmd && cmd[0][++i] != '\0')
    {
      if (cmd[0][i] == '|' || cmd[0][i] == ';' ||
	  cmd[0][i] == '>' || cmd[0][i] == '<')
	cpt = cpt + 1;
    }
  *cmd = epur_str(*cmd);
  return (cpt);
}
