/*
** fct_delimitor.c for  in /home/julien/PSU/PSU_2016_42sh/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Tue May  9 18:50:43 2017 Julien
** Last update Thu May 18 23:55:30 2017 Julien
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "lib.h"
#include "my.h"

int		fct_delimitor(char *cmd)
{
  char		**tab;

  if ((tab = str_to_wordtab(cmd, '|')) == NULL)
    return (-1);
  return (0);
}
