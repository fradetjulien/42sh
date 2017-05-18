/*
** redir.c for  in /home/lenoir/PSU_2016_42sh
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Thu May 18 05:40:10 2017 LENOIR
** Last update Thu May 18 08:24:17 2017 LENOIR
*/

#include "mysh.h"

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i++]);
  return (i);
}

int	apply_left(char **tab, t_cmd cmd)
{
  char	*line;

  line = "";
  if (cmd.red_l == 1)
    {
      if ((line = my_strlcat("", "red_ls ")) == NULL)
	return (BREAK);
    }
  if (cmd.red_l == 2)
    {
      if ((line = my_strlcat("", "red_ld ")) == NULL)
	return (BREAK);
    }
  if (cmd.args == NULL)
    return (BREAK);
  if ((line = my_strlcat(line, cmd.args)) == NULL)
    return (BREAK);
  tab[0] = line;
  return (1);
}

int	apply_right(char **tab, t_cmd cmd, int i)
{
  char	*line;

  if (cmd.red_l == 1)
    {
      if ((line = my_strlcat("", "red_rs ")) == NULL)
	return (BREAK);
    }
  if (cmd.red_l == 2)
    {
      if ((line = my_strlcat("", "red_rd ")) == NULL)
	return (BREAK);
    }
  if (cmd.args == NULL)
    return (BREAK);
  if ((line = my_strlcat(line, cmd.args)) == NULL)
    return (BREAK);
  tab[i] = line;
  tab[i + 1] = NULL;
  return (1);
}

char	**add_redirect(char **tab, t_cmd cmd)
{
  char	**ret;
  int	i;
  int	n;
  
  i = n = 0;
  if ((ret = malloc(tab_len(tab) + 3)) == NULL)
    return (NULL);
  if (cmd.red_l != 0)
    {
      if ((apply_left(ret, cmd)) == BREAK)
	return (NULL);
      i++;
    }
  while (tab[n])
    {
      ret[i] = tab[n];
      i++;
      n++;
    }
  if (cmd.red_r != 0)
    {
      if (apply_right(ret, cmd, i) == BREAK)
	return (NULL);
      return (ret);
    }
  else
    ret[i] = NULL;
  return (ret);
}
