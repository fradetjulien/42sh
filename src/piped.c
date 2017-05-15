/*
** piped.c for  in /home/lenoir/PSU_2016_42sh
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Mon May 15 06:06:41 2017 LENOIR
** Last update Mon May 15 15:16:37 2017 LENOIR
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "mysh.h"

int	exec_biin(char *path, char **args ,char **env)
{

  if (execve(path, args, env) == BREAK)
    return (BREAK);
  return (SUCCES);
}

int	exec_biinaire(char **tab, t_sh *sh, t_cmd cmd)
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
	  exec_biin(path, tab, env_tab(sh->env_list, 0));
	  return (SUCCES);
	}
      free(path);
      i++;
    }
  return (BREAK);
}


int	p_exec(char *cmdd, t_sh *sh)
{
  t_cmd	cmd;
  
  if ((cmd.tab = my_str_to_wordtab(cmdd, ' ')) == NULL)
    return (0);
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
  else if (exec_biinaire(cmd.tab, sh, cmd) == SUCCES);
  else if (my_strcmp(cmd.tab[0], "unsetenv"))
    draw_env(sh->env_list);
  else if ((cmd.tab[0][0] == '.' || cmd.tab[0][0] == '/') &&
	   access(cmd.tab[0], F_OK | X_OK) == 0)
    exec_biin(cmd.tab[0], cmd.tab, env_tab(sh->env_list, 0));
}

int	pipe_sync(char **tab, t_sh *sh, int max)
{
    int	fd[2];
    int	status;
    pid_t	pid;
    int		i;
    int		done;

    done = i = 0;
    if (pipe(fd) == -1)
      return (-1);
    while (done != 1)
      {
	if ((pid = fork()) == -1)
	  return (-1);
	if (pid == 0)
	  {
	    if (i < max)
	      dup2(fd[1], 1);
	    if (i != 0)
	      dup2(fd[0], 0);
	    if (i == max)
	      {
		close(fd[0]);
		close(fd[1]);
	      }
	    p_exec(tab[i], sh);
	  }
	if (i < max)
	  {
	    /*wait(&status)*/;
	    i++;
	  }
	else
	  {printf("okok\n");
	    wait(&status);
	    close(fd[0]);
	    close(fd[1]);
	    done = 1;
	  }
      }
      
}

/*int	pipe_sydnc(char **tab, t_sh *sh, int i, int base)
{
  int	p[2];
  pid_t	pid;
  t_cmd	amd;
  int	statut;
  int	ss;

  pipe(p);
  printf("mm : %s\n", tab[i]);
  pid = fork();
  if (pid == 0)
    {
      close(p[0]);
      dup2(p[1], 1);
      amd.cmd = tab[i];
      p_exec(amd, sh);
    }
  wait(&statut);
  close(p[1]);
  char buff[500];
    int l = read(p[0], buff, 480);
    buff[l] = 0;
    printf("dd:%s\n", buff);
  dup2(p[0], 0);
  pid = fork();
  if (pid == 0)
    {
      amd.cmd = tab[i + 1];
      dup2(p[1], 1);
      p_exec(amd, sh);
    }
  }*/

int	piped_exec(t_cmd cmd, t_sh *sh)
{
  char	**tab;
  int	i;
  
  i = count_char(cmd.cmd, '|');
  if ((tab = my_str_to_wordtab(cmd.cmd, '|')) == NULL)
    return (0);
  pipe_sync(tab, sh, i);
}
