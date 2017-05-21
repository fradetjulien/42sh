/*
** repeat.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sun May 21 10:20:34 2017 Julien
** Last update Sun May 21 11:07:07 2017 Julien
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

int		repeat(char **tab, char **env, char **av, int *error)
{
  char		*chemin;
  int		nb_rep;

  nb_rep = 0;
  if (my_strcmp(tab[0], "repeat") == 0)
    {
      if (my_is_num(tab[1]) == 1)
	{
	  my_putstr(tab[0]);
	  my_putstr(": Badly formed number.\n");
	  *error = 1;
	}
      else if ((chemin = my_access(&tab[2], get_env(env, "PATH="))) != NULL)
	{
	  nb_rep = atoi(tab[1]) + 1;
	  while (--nb_rep)
	    {
	      execute(chemin, av, env, error);
	    }
	}
    }
  return (0);
}
