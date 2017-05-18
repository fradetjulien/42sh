/*
** main.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Tue Mar 21 15:52:06 2017 LENOIR
** Last update Mon May 15 23:25:05 2017 LENOIR
*/

#include "mysh.h"

int             handle_sig_ending()
{
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    return (BREAK);
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    return (BREAK);
    return (1);
}

int             handle_sig()
{
  if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    return (BREAK);
  if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
    return (BREAK);
  return (1);
}

t_sh	*init_sh(char **env)
{
  t_sh	*ret;

  if ((ret = malloc(sizeof(t_sh))) == NULL)
    return (NULL);
  ret->env_list = init_env(env);
  ret->pwd = getcwd(NULL, 0);
  ret->launched = 1;
  ret->count = 0;
  return (ret);
}

int	main(int ac, char **av, char **env)
{
  t_sh	*sh;
  char	*cmd;
  int	i;
  char	**tab;

  i = 0;
  if ((sh = init_sh(env)) == NULL)
    return (NULL);
  draw_prompt(sh);
  if (handle_sig() == BREAK)
    return (0);
  while (sh->launched)
    {
      if ((cmd = get_next_line(0)) == NULL)
	return (0);
      cmd = epur_line(cmd);
      if ((tab = my_str_to_wordtab(cmd, ';')) == NULL)
	return (84);
      while (tab[i])
	exec_cmd(tab[i++], sh);
      draw_prompt(sh);
      i = 0;
    }
}
