/*
** which.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sun May 21 10:02:33 2017 Julien
** Last update Sun May 21 10:11:08 2017 Julien
*/

#include <unistd.h>
#include "lib.h"
#include "my.h"

int		which(char **tab, char **env, int *error)
{
  char		*chemin;

  if (my_strcmp(tab[0], "which") == 0)
    {
      if ((chemin = my_access(&tab[1], get_env(env, "PATH="))) != NULL)
	{
	  my_putstr(chemin);
	  my_putchar('\n');
	}
      else
	{
	  my_putstr(tab[1]);
	  my_putstr(": Command not found.\n");
	  *error = 1;
	}
    }
  return (0);
}
