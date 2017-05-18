/*
** cd_fct.c for  in /home/fradet_j/PSU/PSU_2016_minishell2/src
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 23:14:14 2017 Julien Fradet
** Last update Thu Apr 20 01:59:59 2017 Julien
*/

#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "my.h"

int		check_dir(char **tab)
{
  DIR		*dir;
  int		cpt;
  struct dirent *fichier_lu;
  struct stat	st;

  cpt = 0;
  if ((dir = opendir(".")) == NULL)
    return (-1);
  while ((fichier_lu = readdir(dir)))
    if (my_strcmp(fichier_lu->d_name, tab[1]) == 0)
      cpt = 1;
  if (closedir(dir) == -1)
    return (84);
  if (cpt == 1)
    if ((stat(tab[1], &st)) == 0)
      if (S_ISDIR(st.st_mode))
	return (0);
  return (1);
}

char		**get_pwd(char **ev)
{
  char		*tmp;
  char		*pwd_tmp;
  char		*pwd;
  int		i;

  i = -1;
  if ((tmp = malloc(sizeof(char) * 255)) == NULL)
    return (NULL);
  getcwd(tmp, 255);
  pwd_tmp = my_strdup(tmp);
  free(tmp);
  while (ev && my_strncmp(ev[++i], "PWD", my_strlen("PWD")) != 0);
  free(ev[i]);
  pwd = my_concat("PWD", '=', pwd_tmp);
  if ((ev[i] = malloc(sizeof(char) * my_strlen(pwd))) == NULL)
    return (NULL);
  ev[i] = my_strdup(pwd);
  free(pwd);
  free(pwd_tmp);
  return (ev);
}

char		*get_oldpwd(char **ev)
{
  char		*pwd;
  int		i;

  i = -1;
  while (ev && my_strncmp(ev[++i], "PWD", my_strlen("PWD")) != 0);
  pwd = my_strdup(ev[i]);
  pwd = pwd + 4;
  return (pwd);
}

char		**path_oldpwd(char **ev, char *pwd)
{
  int		i;
  char		*old_pwd;

  i = -1;
  while (ev && (my_strncmp(ev[++i], "OLDPWD", my_strlen("OLDPWD"))) != 0);
  free(ev[i]);
  old_pwd = my_concat("OLDPWD", '=', pwd);
  if ((ev[i] = malloc(sizeof(char) * my_strlen(old_pwd))) == NULL)
    return (NULL);
  ev[i] = my_strdup(old_pwd);
  free(old_pwd);
  return (ev);
}

int		cd_fct(char *cmd, char **tab, char ***ev, int *error)
{
  char		*path;
  char		*pwd;

  pwd = NULL;
  if (my_strcmp(cmd, "cd") == 0 && tab[1] != NULL)
    {
      if ((path = malloc(sizeof(char *) * my_strlen(tab[1]))) == NULL)
	return (-1);
      if ((my_strcmp(tab[1], "-") == 0) && (*ev != NULL)) cd_tiret(ev, pwd, error);
      else if ((check_dir(tab)) == 0 || tab[1][0] == '/')
	{
	  pwd = get_oldpwd(*ev);
	  *ev = path_oldpwd(*ev, pwd);
	  path = my_strcpy(path, tab[1]);
	  if ((chdir(path)) == -1) return (1);
	  *ev = get_pwd(*ev);
	}
      else
	{
	  my_putstr(tab[1]); my_putstr(": Not a directory.\n");
	  *error = 1;
	}
      free(path);
    }
  return (0);
}
