/*
** case_enter.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Mon Apr  3 11:57:49 2017 Julien Fradet
** Last update Mon Apr  3 12:05:22 2017 Julien Fradet
*/

#include "my.h"

int		case_enter(char *cmd)
{
  if (cmd[0] == '\0')
    {
      check_isat();
      return (1);
    }
  return (0);
}
