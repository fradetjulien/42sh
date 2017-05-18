/*
** piped.c for  in /home/lenoir/PSU_2016_42sh
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Mon May 15 06:06:41 2017 LENOIR
** Last update Thu May 18 08:25:07 2017 LENOIR
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

int	exec_biinaire(char **tab, t_sh *sh)
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
	return (exec_biin(path, tab, env_tab(sh->env_list, 0)));
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
  else if (my_strcmp(cmd.tab[0], "unsetenv"))
    draw_env(sh->env_list);
  else
    return (0);
  return (1);
}

static int	ex_father(pid_t pid, int *pfd, int *fdin, char **tab)
{
  int	status;
  
  waitpid(pid, &status, 0);
  close(pfd[1]);
  *fdin = pfd[0];
  if (my_strcmp(tab[0], "exit") == 1)
    {
      if (tab[1] && my_str_isnum(tab[1]))
	exit(my_getnbr(tab[1]));
      else
	exit(84);
    }
}

static int	ex_son(t_pipe *p, int *pfd, int fdin, int i)
{
  int	res;

  res = 0;
  if (i != 0 && dup2(fdin, 0) < 0)
    return (-1);
  if (i < p->max)
    {
      dup2(pfd[1], 1);
      close(pfd[0]);
    }
  if (exec_biinaire(p->tabe, p->sh) == 1);
  else if ((p->tabe[0][0] == '.' || p->tabe[0][0] == '/') &&
	   access(p->tabe[0], F_OK | X_OK) == 0)
    return (exec_biin(p->tabe[0], p->tabe, env_tab(p->sh->env_list, 0)));
  else
    return (0);
}

static int	pipe_sync(t_pipe *p, int *fdin)
{
  pid_t         pid;
  char		**tabe;
  int           pfd[2];
  int           res;
  int		i;
  
  i = res = 0;
  while (p->tab[i] != NULL)
    {
      pipe(pfd);
      if (p_exec(p->tab[i], p->sh))
        i++;
      else
	{
	  if ((pid = fork()) < 0)
	    return (-1);
	  if ((p->tabe = my_str_to_wordtab(p->tab[i], ' ')) == NULL)
	    return (-1);
	  if (pid == 0)
	res = ex_son(p, pfd, *fdin, i);
	  else
	    {
	      ex_father(pid, pfd, fdin, p->tabe);
	      i++;
	    }
	}
    }
  return (res);
}

int	piped_exec(t_cmd cmd, t_sh *sh)
{
  char	**tab;
  int	i;
  int	fdin;
  t_pipe	p;
  
  p.max = count_char(cmd.cmd, '|'); 
  if ((p.tab = my_str_to_wordtab(cmd.cmd, '|')) == NULL)
    return (BREAK);
  /*if ((p.tab = add_redirect(p.tab, cmd)) == NULL)
    return (BREAK);
  int l = -1;
  while (p.tab[++l])
  printf("--%s\n", p.tab[l]);*/
  p.sh = sh;
  pipe_sync(&p, &fdin);
}
