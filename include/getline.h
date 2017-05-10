/*
** getline.h for  in /home/lenoir/rendu/tetris
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Mon Mar  6 22:45:08 2017 LENOIR
** Last update Wed Mar  8 01:12:32 2017 LENOIR
*/

#ifndef READ_SIZE
# define READ_SIZE      14

#endif  /* !READ_SIZE*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct          s_buffer
{
  char                  *data;
  struct s_buffer       *next;
}                       t_buffer;

t_buffer        *add_elem(t_buffer *ptr, char *data);
char            *fill_buffer(t_buffer *ptr, int max);
int             check_line(char *buf, int ret);
t_buffer        *my_read(const int fd, t_buffer *first, char* buf, char **all);

#endif /* !GET_NEXT_LINE_H_ */
