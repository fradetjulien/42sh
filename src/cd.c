/*
** cd_command.c for  in /home/lenoir/rendu/PSU_2015_minishell2
**
** Made by lenoir_g
** Login   <guillaume.lenoir@epitech.net>
**
** Started on  Sun Apr 10 04:32:35 2016 lenoir_g
** Last update Sun Apr  9 17:29:46 2017 LENOIR
*/

#include "mysh.h"

int		go_old_pwd(t_env *env_list)
{
  char	*dir;

  if ((dir = get_env_var(env_list, "OLDPWD")) == NULL)
    my_putstr("bash: cd: « OLDPWD » non défini.\n");
  else
    {
      if (chdir(dir) == -1)
	return (BREAK);
    }
  return (SUCCES);
}

int		go_newdir(t_env *env_list, char *dir)
{
  (void)env_list;
  if (chdir(dir) == -1)
    return (BREAK);
  return (SUCCES);
}

int		simple_cd(t_sh *shell)
{
  char	*home;

  set_env_var(shell->env_list, "OLDPWD", getcwd(NULL, 0));
  home = get_env_var(shell->env_list, "HOME");
  if (chdir(home) == -1)
    return (BREAK);
  shell->pwd = getcwd(NULL, 0);
  return (SUCCES);
}

int		args_cd(char **tab, t_sh *sh)
{
  if (my_strcmp(tab[1], "-") == 0)
    {
      set_env_var(sh->env_list, "OLDPWD", getcwd(NULL, 0));
      go_newdir(sh->env_list, tab[1]);
    }
  else
    {
      my_printf("%s\n", get_env_var(sh->env_list, "OLDPWD"));
      go_old_pwd(sh->env_list);
      set_env_var(sh->env_list, "OLDPWD", getcwd(NULL, 0));
    }
  sh->pwd = getcwd(NULL, 0);
  return (SUCCES);
}

int	cd_command(t_cmd cmd, t_sh *sh)
{
  if (cmd.tab[1])
    args_cd(cmd.tab, sh);
  else
    simple_cd(sh);
}
