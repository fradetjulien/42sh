/*
** exit_shell.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 19:12:36 2017 Julien Fradet
** Last update Sat May 20 05:46:09 2017 Julien
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"

int		exit_shell(char **tab, int i, int *error)
{
  char		*str;
  int		nb;

  i = -1;
  if ((str = malloc(sizeof(char) * my_strlen(tab[1]) + 1)) == NULL)
    return (-1);
  if (tab[1] != NULL)
    {
      str = my_strcpy(str, tab[1]);
      while (str && str[++i] != '\0')
	{
	  if (str[i] < 48 || str[i] > 57)
	    {
	      my_putstr("exit: Expression Syntax.\n");
	      *error = 1; return (1);
	    }
	  else
	    {
	      nb = my_getnbr(str);
	      exit(nb);
	    }
	}
    }
  free(str);
  return (0);
}

int		exit_fct(char *cmd, char **tab, int *error)
{
  int           rt;
  int           cpt;
  int           i;

  cpt = 0;
  i = -1;
  if (my_strcmp(cmd, "exit") == 0)
    {
      while (tab[++i] != NULL)
        cpt++;
      if (cpt > 2)
	{
	  my_putstr("exit: Expression Syntax.\n");
	  *error = 1; return (1);
	}
      else
        rt = exit_shell(tab, i, error);
      if (rt == 0)
        {
	  free(cmd);
	  my_putstr("exit\n");
          exit(0);
        }
    }
  return (0);
}
