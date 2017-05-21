/*
** where.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sun May 21 09:48:19 2017 Julien
** Last update Sun May 21 10:01:09 2017 Julien
*/

#include <unistd.h>
#include "lib.h"
#include "my.h"

int		where(char **tab, char **env, int *error)
{
  char		*chemin;

  if (my_strcmp(tab[0], "where") == 0)
    {
      if ((chemin = my_access(&tab[1], get_env(env, "PATH="))) != NULL)
	{
	  my_putstr(chemin);
	  my_putchar('\n');
	}
      else
	*error = 1;
    }
  return (0);
}
