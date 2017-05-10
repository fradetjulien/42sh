/*
** env_func.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Thu Mar 23 14:52:42 2017 LENOIR
** Last update Wed May 10 01:25:08 2017 LENOIR
*/

#include "mysh.h"

char	*get_env_var(t_env *env, char *name)
{
  while (env)
    {
      if (env->visible && my_strcmp(name, env->name))
	return (env->var);
      env = env->next;
    }
  return (NULL);
}

char	del_env_var(t_env *env, char *name)
{
  while (env)
    {
      if (env->visible && my_strcmp(name, env->name))
	env->visible = 0;;
      env = env->next;
    }
  return (1);
}

int	set_env_var(t_env *env, char *name, char *value)
{
  char	*line;

  while (env && env->name)
    {
       if (my_strcmp(name, env->name))
	{
	  env->var = value;
	  env->visible = 1;
	  return (1);
	}
      env = env->next;
    }
  line = my_strlcat("", name);
  line = my_strlcat(line, "=");
  line = my_strlcat(line, value);
  env_add(env, line);
  return (1);
}
 
char	**env_tab(t_env *list, int o)
{
  int	i;
  t_env	*count;
  char	**tab;
  char	*line;

  count = list;
  i = o = 0;
  while ((count = count->next) != NULL)
    i++;
  if ((tab = malloc((i + 2) * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (list && o == 0)
    {
      line = my_strlcat("", list->name);
      line = my_strlcat(line, "=");
      line = my_strlcat(line, list->var);
      if (list->visible)
	tab[i++] = line; //check
      if (list->next != NULL)
	list = list->next;
      else
	o = 1;
    }
  tab[i] = NULL;
  return (tab);
}

int	draw_env(t_env *list)
{
  char	**envtab;
  int	i;

  i = 0;
  envtab = env_tab(list, 0);
  while (envtab[i])
    {
      my_putstr(envtab[i]);
      my_putchar('\n');
      i++;
    }
  return (1);
}
