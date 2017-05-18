/*
** redirect.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Fri Apr  7 23:09:17 2017 LENOIR
** Last update Thu May 18 05:22:07 2017 LENOIR
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

char	*get_vlined(char *line, char d)
{
  while (line[0])
    {
      if (line[0] != d)
	line++;
      else
	{
	  line++;
	  return (line);
	}
    }
  return (NULL);
}

char	*get_vargs(char *c, char d)
{
  int	i;
  char	*line;

  if ((line = my_strdup(c)) == NULL)
    return (NULL);
  i = 0;
  while (line[i] && line[i] != d)
    i++;
  line[i] = 0;
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
  if (cmd->red_r != 0)
    return (NULL);
  cmd->red_r = 2;
  if (line[0] == '>')
    {
      line = line + 2;
      if (count_char(line, ' ') == 0)
	return (NULL);
      cmd->args = get_vargs(line, ' ');
      return (get_vlined(line, ' '));
    }
  cmd->args = get_args(line, '>');
  return (get_lined(line, '>'));
}

char	*sr_red(char *line, t_cmd *cmd)
{
  int	i;
  char	*args;
  int	fd;

  i = 0;
  if (cmd->red_r != 0)
    return (NULL);
  cmd->red_r = 1;
  if (line[0] == '>')
    {
      line = line + 1;
      if (count_char(line, ' ') == 0)
	return (NULL);
      cmd->args = get_vargs(line, ' ');
      return (get_vlined(line, ' '));
    }
  cmd->args = get_args(line, '>');
  return (get_lined(line, '>'));
}

char	*dl_red(char *line, t_cmd *cmd)
{
  int	i;
  char	*args;
  int	fd;

  i = 0;
  if (cmd->red_l != 0)
    return (NULL);
  cmd->red_l = 2;
  if (line[0] == '<')
    {
      line = line + 2;
      if (count_char(line, ' ') == 0)
	return (NULL);
      cmd->args = get_vargs(line, ' ');
      return (get_vlined(line, ' '));
    }
  cmd->args = get_args(line, '<');
  return (get_lined(line, '<'));
}

char	*sl_red(char *line, t_cmd *cmd)
{
  int	i;
  char	*args;
  int	fd;

  i = 0;
  if (cmd->red_l != 0)
    return (NULL);
  cmd->red_l = 1;
  if (line[0] == '<')
    {
      line = line + 1;
      if (count_char(line, ' ') == 0)
	return (NULL);
      cmd->args = get_vargs(line, ' ');
      return (get_vlined(line, ' '));
    }
  cmd->args = get_args(line, '<');
  return (get_lined(line, '<'));
}
