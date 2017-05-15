/*
** my.h for  in /home/lenoir_g/rendu/Piscine_C_bistromathique/lib/my
**
** Made by guillaume lenoir
** Login   <lenoir_g@epitech.net>
**
** Started on  Wed Nov  4 03:34:57 2015 guillaume lenoir
** Last update Mon May 15 13:33:55 2017 LENOIR
*/

#ifndef	MYSH_H_
# define MYSH_H_

#include <sys/ioctl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include "my.h"

# define BREAK -1
# define SUCCES 0

typedef	struct	s_env
{
  char	*name;
  char	*var;
  int	visible;
  struct s_env	*next;
}		t_env;

typedef struct	s_sh
{
  t_env	*env_list;
  char	*pwd;
  int	launched;
  int	count;
}		t_sh;

typedef struct	s_cmd
{
  char	*cmd;
  char	**tab;
  int	redirect;
  int	fdred;
  char	*args;
  char	***pipe;
}		t_cmd;

t_env	*env_add(t_env *list, char *data);
t_env	*init_env(char **env);
char	*get_env_var(t_env *b, char *name);
char	del_env_var(t_env *b, char *name);
  int	set_env_var(t_env *b, char *name, char *value);
char	**env_tab(t_env *b, int o);
int	draw_env(t_env *list);
char	*epur_line(char *line);
int	exec_cmd(char *c, t_sh *sh);
int	draw_prompt(t_sh *sh);
char	*dr_red(char *line, t_cmd *cmd);
int	classic_exec(t_cmd cmd, t_sh *sh, int);
int	cd_command(t_cmd cmd, t_sh *sh);

#endif	/* MYSH_H_ */
