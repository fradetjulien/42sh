/*
** exec.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Fri Apr  7 06:53:36 2017 LENOIR
** Last update Thu May 18 08:23:40 2017 LENOIR
*/

#include "mysh.h"

char	*extrude_red_r(char *c, t_cmd *cmd)
{
  char	*line;

  if (my_strstr(c, ">>") != NULL)
    return (dr_red(c, cmd));
  else if ((line = my_strstr(c, ">")) != NULL)
    return (sr_red(line, cmd));
  return (c);
}

char	*extrude_red_l(char *c, t_cmd *cmd)
{
  char	*line;

  if ((line = my_strstr(c, "<<")) != NULL)
    return (dl_red(line, cmd));
  else if ((line = my_strstr(c, "<")) != NULL)
    return (sl_red(line, cmd));
  return (c);
}

int	exec_cmd(char *c, t_sh *sh)
{
  t_cmd	cmd;

  cmd.cmd = c;
  cmd.args = NULL;
  cmd.red_r = 0;
  cmd.red_l = 0;
  /*if ((cmd.cmd = extrude_red_r(cmd.cmd, &cmd)) == NULL)
    return (BREAK);
  if ((cmd.cmd = extrude_red_l(cmd.cmd, &cmd)) == NULL)
  return (BREAK);*/
  return (piped_exec(cmd, sh));
}
