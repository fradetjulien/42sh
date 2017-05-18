/*
** permissions.c for  in /home/julien/PSU/PSU_2016_42sh/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Tue May  9 19:39:30 2017 Julien
** Last update Thu May 18 07:19:28 2017 Julien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

int		permissions(char *cmd, int *error)
{
  struct stat	info;

  if ((stat(cmd, &info)) == -1)
    return (-1);
  if (S_ISDIR(info.st_mode))
    {
      my_putstr("Permission denied\n");
      *error = 1;
      return (-1);
    }
  if (info.st_mode && S_IXUSR)
    return (0);
  return (0);
}

int		permissions_bis(char *cmd, int *error)
{
  struct stat   info;
  char          *epur;

  epur = my_strdup(cmd);
  epur = epur + 2;
  cmd = my_strdup(epur);
  if ((stat(cmd, &info)) == -1)
    return (-1);
  if (S_ISDIR(info.st_mode))
    {
      my_putstr("Permission denied\n");
      *error = 1;
      return (-1);
    }
  if (info.st_mode && S_IXUSR)
    return (0);
  return (0);
}
