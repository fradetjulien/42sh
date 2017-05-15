/*
** redirect.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Fri Apr  7 23:09:17 2017 LENOIR
** Last update Mon May 15 00:58:50 2017 LENOIR
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mysh.h"

char	*get_lined(char *line, char d)
{
  int	i;

  i = 0;
  if (line[0] == d)
    {
      while (line[0] && line[0] != ' ')
	line++;
      if (line[1])
	line++;
      return (line);
    }
  while (line[i])
    {
      if (line[i] == d)
	line[i] = 0;
      i++;
    }
  return (line);
}

char	*get_args(char *c, char d)
{
  int	i;
  char	*line;

  if ((line = my_strdup(c)) == NULL)
    return (NULL);
  i = 0;
  if (line[0] == d)
    {
      while (line[0] && line[0] == d)
	line++;
      while (line[i] != ' ')
        i++;
      line[i] = 0;
      return (line);
    }
  while (line[i] && line[i] != d)
    line++;
  while (line[i] && line[i] == d)
    line++;
  return (line);

}

char	*dr_red(char *line, t_cmd *cmd)
{
  int	i;
  char	*args;
  int	fd;

  i = 0;
  cmd->redirect = 2;
  cmd->args = get_args(line, '>');
  /*if ((fd = open(cmd->args, O_CREAT | O_APPEND | O_WRONLY, 0644)) == -1)
    return (NULL);*/
  cmd->fdred = fd;
  return (get_lined(line, '>'));
}
