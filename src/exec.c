/*
** exec.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Fri Apr  7 06:53:36 2017 LENOIR
** Last update Mon May 15 06:14:12 2017 LENOIR
*/

#include "mysh.h"

char	*extrude_red(char *c, t_cmd *cmd)
{
  char	*line;

  if (my_strstr(c, ">>") != NULL)
    return (dr_red(c, cmd));
  /*else if ((line = my_strstr(c, ">")) != NULL)
    return (sr_red(line, cmd));
  else if ((line = my_strstr(c, "<")) != NULL)
    return (dl_red(line, cmd));
  else if ((line = my_strstr(c, "<<")) != NULL)
  return (sl_red(line, cmd));*/
  return (c);
}

int	exec_cmd(char *c, t_sh *sh)
{
  t_cmd	cmd;

  cmd.cmd = c;
  cmd.fdred = -1;
  cmd.cmd = extrude_red(cmd.cmd, &cmd);
  if (count_char(cmd.cmd, '|') == 0)
    return (classic_exec(cmd, sh, 1));
  else
    return (piped_exec(cmd, sh));
  
}
