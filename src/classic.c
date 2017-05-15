/*
** classic.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Sat Apr  8 05:45:22 2017 LENOIR
** Last update Mon May 15 06:36:07 2017 LENOIR
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "mysh.h"

int	exec_bin(char *path, char **args ,char **env, char *entree)
{
  int	status;
  pid_t	pid;
  
  if ((pid = fork()) == BREAK)
    return (BREAK);
  if (pid == 0)
    {
      if (execve(path, args, env) == BREAK)
	return (BREAK);
    }
  else
    {
      wait(&status);
    }
  return (SUCCES);
}

int	exec_binaire(char **tab, t_sh *sh, t_cmd cmd)
{
  int	i;
  char	*path;
  char	**bin_path;
  char	*env_line;
  
  i = 0;
  if ((env_line = get_env_var(sh->env_list, "PATH")) == NULL)
    return (BREAK);
  if ((bin_path = my_str_to_wordtab(env_line, ':')) == NULL)
    return (BREAK);
  while (bin_path[i])
    {
      path = my_strlcat("", bin_path[i]);
      path = my_strlcat(path, "/");
      path = my_strlcat(path, tab[0]);
      if (access(path, F_OK | X_OK) == 0)
	{
	  exec_bin(path, tab, env_tab(sh->env_list, 0), "guigui");
	  return (SUCCES);
	}
      free(path);
      i++;
    }
  return (BREAK);
}


int	classic_exec(t_cmd cmd, t_sh *sh, int fd)
{
  if ((cmd.tab = my_str_to_wordtab(cmd.cmd, ' ')) == NULL)
    return (0);
  /*if (fd != 1)
    dup2(fd, 1);*/
  else if (my_strcmp(cmd.tab[0], "exit"))
    {
      if (cmd.tab[1] && my_is_digit(cmd.tab[1]))
	my_exit(my_getnbr(cmd.tab[1]));
      my_exit(84);
    }
  else if (my_strcmp(cmd.tab[0], "cd"))
    cd_command(cmd, sh);
  else if (my_strcmp(cmd.tab[0], "pwd"))
    my_printf("%s\n", getcwd(NULL, 0));
  else if (my_strcmp(cmd.tab[0], "env"))
    draw_env(sh->env_list);
  else if (my_strcmp(cmd.tab[0], "setenv"))
    draw_env(sh->env_list);
  else if (exec_binaire(cmd.tab, sh, cmd) == SUCCES);
  else if (my_strcmp(cmd.tab[0], "unsetenv"))
    draw_env(sh->env_list);
  else if ((cmd.tab[0][0] == '.' || cmd.tab[0][0] == '/') &&
	   access(cmd.tab[0], F_OK | X_OK) == 0)
    exec_bin(cmd.tab[0], cmd.tab, env_tab(sh->env_list, 0), "");
  
}
