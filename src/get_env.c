/*
** get_env.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 16:07:51 2017 Julien Fradet
** Last update Thu Apr 20 02:01:41 2017 Julien
*/

#include <unistd.h>
#include "lib.h"
#include "my.h"

char		*get_env(char **env, char *varname)
{
  int		i;

  i = -1;
  varname = epur_str(varname);
  while (env && env[++i] != NULL)
    {
      if (my_strncmp(env[i], varname, my_strlen(varname)) == 0)
	return (env[i]);
    }
  return (NULL);
}
