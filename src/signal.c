/*
** signal.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Apr  5 12:49:36 2017 Julien Fradet
** Last update Tue May 16 01:16:10 2017 Julien
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "lib.h"
#include "my.h"

int		signal_check(int result, int *error)
{
  if (WTERMSIG(result) == SIGSEGV)
    {
      my_putstr("Segmentation fault");
      if (WCOREDUMP(result))
	my_putstr(" (core dumped)\n");
      else
	my_putchar('\n');
      *error = 139;
    }
  if (WTERMSIG(result) == SIGFPE)
    {
      my_putstr("Floating exception");
      if (WCOREDUMP(result))
	my_putstr(" (core dumped)\n");
      else
	my_putchar('\n');
      *error = 136;
    }
  return (result);
}
