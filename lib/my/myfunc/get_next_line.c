/*
** get_next_line.c for  in /home/lenoir/rendu/PSU_2016_my_sokoban
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Thu Dec 15 01:49:05 2016 LENOIR
** Last update Wed Mar  8 01:13:12 2017 LENOIR
*/

#include "my.h"
#include "getline.h"

t_buffer	*add_elem(t_buffer *elem, char *data)
{
  t_buffer	*first;

  first = elem;
  if (elem == NULL)
    {
      if ((elem = malloc(sizeof(t_buffer))) == NULL)
	return (NULL);
      elem->data = data;
      elem->next = NULL;
      return (elem);
    }
  while (elem->next)
    elem = elem->next;
  if ((elem->next = malloc(sizeof(t_buffer))) == NULL)
    return (NULL);
  elem->next->data = data;
  elem->next->next = NULL;
  return (first);
}

char	*fill_buffer(t_buffer *elem, int max)
{
  char	*new_str;
  int	n;
  int	i;

  if ((new_str = malloc(max * READ_SIZE + 1)) == NULL)
    return (NULL);
  i = 0;
  while (elem)
    {
      n = 0;
      while (elem->data[n] && elem->data[n] != '\n')
	{
	  new_str[i] = elem->data[n];
	  n++;
	  i++;
	}
      elem = elem->next;
    }
  new_str[i] = '\0';
  return (new_str);
}

int	check_line(char *buf, int ret)
{
  int	i;

  i = 0;
  if (ret != READ_SIZE)
    return (0);
  if ((buf) == NULL)
    return (1);
  while (buf[i])
    {
      if (buf[i] == '\n')
	return (0);
      i = i + 1;
    }
  return (1);
}

t_buffer	*my_read(const int fd, t_buffer *elem, char *buffer,
			 char **line)
{
  int	count;
  int	ret;

  count = 1;
  ret = READ_SIZE;
  while (check_line(buffer, ret))
    {
      if ((buffer = malloc(READ_SIZE + 1)) == NULL)
	return (NULL);
      if ((ret = read(fd, buffer, READ_SIZE)) <= 0)
	return (0);
      buffer[ret] = '\0';
      if ((elem = add_elem(elem, buffer)) == NULL)
	return (NULL);
      count++;
    }
  *line = fill_buffer(elem, count);
  return (elem);
}

char		*get_next_line(const int fd)
{
  static char	file[READ_SIZE + 1];
  t_buffer     	*elem;
  char		*buffer;
  char		*line;
  int		i;

  buffer = file;
  if ((elem = add_elem(NULL, buffer)) == NULL)
    return (NULL);
  if ((elem = my_read(fd, elem, buffer, &line)) == NULL)
    return (NULL);
  i = -1;
  while (elem->next != NULL)
    elem = elem->next;
  while (*elem->data && *elem->data != '\n')
    elem->data = elem->data + 1;
  while (*(elem->data = elem->data + 1))
    file[(i = i + 1)] = *elem->data;
  file[i + 1] = '\0';
  return (line);
}
