/*
** redirections.c for  in /home/julien/PSU/PSU_2016_42sh/src
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Mon May  8 22:09:07 2017 Julien
** Last update Wed May 10 16:47:54 2017 Julien
*/

# define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "lib.h"
#include "my.h"

int		complete_file(char *file)
{
  int		i;

  i = 1;
  while (file[++i] != '\0');
  return (0);
}

int		create_file(char *file)
{
  int		i;

  i = -1;
  while (file[++i] != '\0');
  return (0);
}

int		file_name(char *read_file, char *file)
{
  if (my_strcmp(file, read_file) == 0)
    return (1);
  return (0);
}

int		redirections(char *file)
{
  DIR		*directory;
  struct dirent *fichier_lu;
  char		*dir_name;
  int		indice;

  indice = 0;
  fichier_lu = NULL;
  directory = NULL;
  dir_name = NULL;
  dir_name = get_current_dir_name();
  if ((directory = opendir(dir_name)) == NULL)
    return (84);
  while ((fichier_lu = readdir(directory)))
    if (file_name(fichier_lu->d_name, file) == 1)
      {
	file = my_strdup(fichier_lu->d_name);
	indice = 1;
      }
  if (indice == 0)
    complete_file(file);
  else if (indice == 1)
    create_file(file);
  if (closedir(directory) == -1)
    return (84);
  return (0);
}
