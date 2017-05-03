/*
** annexe.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Thu Apr  6 17:22:31 2017 Julien Fradet
** Last update Thu Apr 20 01:59:07 2017 Julien
*/

#include "lib.h"
#include "my.h"

int		annexe(char *cmd, char **ev)
{
  int		cpt;

  cpt = 0;
  if (my_strcmp(cmd, "env") == 0)
    {
      env_fct(ev);
      cpt = 1;
    }
  else if (case_enter(cmd) == 1)
    cpt = 1;
  return (cpt);
}
