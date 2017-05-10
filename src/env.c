/*
** env.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Tue Mar 21 16:50:22 2017 LENOIR
** Last update Sun Apr  9 14:40:52 2017 LENOIR
*/

#include "mysh.h"

char	**my_str_wordtab(char *data)
{
  char	**ret;
  int	i;
  int	c;

  c = 0;
  i = -1;
  if ((ret = malloc(3 * sizeof(char *))) == NULL)
    return (NULL);
  while (data[++i] != '=');
  if ((ret[0] = malloc(i + 1)) == NULL)
    return (NULL);
  if ((ret[1] = malloc(my_strlen(data) - i + 1)) == NULL)
    return (NULL);
  ret[2] = NULL;
  i = -1;
  while (data[++i] != '=')
    ret[0][i] = data[i];
  ret[0][i] = 0;
  while (data[++i])
    ret[1][c++] = data[i];
  ret[1][c] = 0;
  return (ret);
}

t_env	*create_elem(char *data)
{
  t_env	*elem;
  char	**tab;

  if ((tab = my_str_wordtab(data)) == NULL)
    return (NULL);
  if ((elem = malloc(sizeof(t_env))) == NULL)
    return (NULL);
  elem->name = tab[0];
  elem->var = tab[1];
  elem->visible = 1;
  elem->next = NULL;
  return (elem);
}

t_env	*env_add(t_env *list, char *data)
{
  t_env	*elem;
  t_env	*save;
  
  if ((elem = create_elem(data)) == NULL)
    return (NULL);
  save = list;
  if (list == NULL)
    return (elem);
  while (list->next != NULL)
    list = list->next;
  list->next = elem;
  return (save);
}

t_env	*init_env(char **env)
{
  int	i;
  t_env	*list;

  i = 0;
  list = NULL;
  while (env[i])
    {
      list = env_add(list, env[i]);
      i++;
    }
  return (list);
}
