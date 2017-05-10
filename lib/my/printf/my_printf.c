/*
** my_printf.c for  in /home/lenoir_g/PSU_2016_my_printf
**
** Made by Guillaume LENOIR
** Login   <lenoir_g@epitech.net>
**
** Started on  Wed Nov 16 15:49:22 2016 Guillaume LENOIR
** Last update Mar Dec 6 09:35:07 2016
*/

#include <stdlib.h>
#include "my.h"

t_prin	*init_print(char *s)
{
  t_prin	*ret;

  if (my_strlen(s) == 0)
    return (NULL);
  if ((ret = malloc(sizeof(t_prin))) == NULL)
    return (NULL);
  ret->next = NULL;
  ret->c = s[0];
  return (ret);
}

t_prin	*add_char(char c, t_prin *t)
{
  t_prin	*ret;
  t_prin	*save;
  int		i;

  i = 0;
  if ((ret = malloc(sizeof(t_prin))) == NULL)
    return (NULL);
  ret->next = NULL;
  ret->c = c;
  save = t;
  while (t->next != NULL)
    t = t->next;
  t->next = ret;
  return (save);
}

char	*form(t_prin *t)
{
  t = t->next;
  while (t->next != NULL)
    {
      my_putchar(t->c);
      t = t->next;
    }
  my_putchar(t->c);
}

int	use_flag(char *s, int i, t_fla *p, t_prin *e)
{
  int	j;

  j = 0;
  while (s[i] == ' ')
    i++;
  while (p->tab[j])
    {
      if (s[i] == p->tab[j])
	p->fl[j](p->ap, e);
      j++;
    }
  return (i);
}

int	my_printf(char *s, ...)
{
  int		i;
  t_prin	*print;
  t_fla		*p;

  if ((p = malloc(sizeof(t_fla))) == NULL)
    return (0);
  va_start(p->ap, s);
  i = 0;
  if ((p->tab = init_char()) == NULL ||
      (p->fl = init_func()) == NULL)
    return (0);
  if ((print = init_print(s)) == NULL)
    return (0);
  while (s[i])
    {
      if (s[i] != '%')
	add_char(s[i], print);
      else
	i = use_flag(s, ++i, p, print);
      i++;
    }
  va_end(p->ap);
  form(print);
}
