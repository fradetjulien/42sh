/*
** echo.c for  in /home/julien/PSU/repo_robin/my/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Sun May 21 06:57:19 2017 Julien
** Last update Sun May 21 08:57:13 2017 Julien
*/

#include <unistd.h>
#include "lib.h"
#include "my.h"

int		echo_e(char **tab)
{
  int		i;

  i = -1;
  my_putstr(tab[1]);
  my_putchar(' ');
  while (tab && tab[2][++i] != '\0')
    {
      if (tab[2][i] == '\\' && tab[2][i + 1] == 'n')
	{
	  my_putchar('\n');
	  i = i + 2;
	}
      if (tab[2][i] != '"')
	my_putchar(tab[2][i]);
    }
  my_putchar('\n');
  return (0);
}

int		echo_n(char **tab)
{
  int		i;
  int		cpt;
  int		comp;

  comp = 0;
  cpt = 0;
  i = -1;
  while (tab && tab[2][++i] != '\0')
    if (tab[2][i] == '\\' && tab[2][i + 1] == 'n')
      cpt++;
  i = -1;
  while (tab && tab[2][++i] != '\0')
    {
      if (tab[2][i] == '\\' && tab[2][i + 1] == 'n' && comp <= cpt - 1)
	{
	  my_putchar('\n');
	  i = i + 1;
	  comp++;
	}
      else if (tab[2][i] != '"')
	my_putchar(tab[2][i]);
    }
  return (0);
}

int		echo_classic_E(char **tab)
{
  int		i;

  i = -1;
  while (tab && tab[2][++i] != '\0')
    {
      if (tab[2][i] == '\\' && tab[2][i + 1] == 'n')
	{
	  my_putchar('\n');
	  i = i + 2;
	}
      else if (tab[2][i] != '"')
	my_putchar(tab[2][i]);
    }
  my_putchar('\n');
  return (0);
}

int		echo_classic(char **tab)
{
  int		i;

  i = -1;
  while (tab && tab[1][++i] != '\0')
    {
      if (tab[1][i] == '\\' && tab[1][i + 1] == 'n')
	{
	  my_putchar('\n');
	  i = i + 2;
	}
      else if (tab[1][i] != '"')
	my_putchar(tab[1][i]);
    }
  my_putchar('\n');
  return (0);
}

int		echo(char **tab)
{
  if (my_strncmp(tab[0], "echo", 4) == 0)
    {
      if ((my_strcmp(tab[1], "-n") == 0) && tab[2] != NULL)
	echo_n(tab);
      else if ((my_strcmp(tab[1], "-e") == 0) && tab[2] != NULL)
	echo_e(tab);
      else if ((my_strcmp(tab[1], "-E") == 0) &&  tab[2] != NULL)
	echo_classic_E(tab);
      else if (tab[1] != NULL && tab[2] == NULL)
	echo_classic(tab);
    }
  return (0);
}
