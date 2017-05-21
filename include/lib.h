/*
** lib.h for  in /home/julien/PSU/PSU_2016_minishell2/include
** 
** Made by Julien
** Login   <julien@epitech.net>
** 
** Started on  Thu Apr 20 01:53:14 2017 Julien
** Last update Sun May 21 10:47:21 2017 Julien
*/

#ifndef LIB_H_
# define LIB_H_

char	**str_to_wordtab(char *, char);
char	**my_realloc_tab(char **, int);
char	**my_unalloc_tab(char **, char *);
char	*epur_str(char *);
char    *my_strcat(char *, const char *);
char    *my_strdup(char *);
char    *show_wordtab(char **);
char    *my_concat(char *, char, char  *);
char	*my_strcpy(char *, const char *);
int     my_strncmp(char *, char *, int);
int     my_strcmp(char *, char *);
int     my_strlen(char *);
int	my_getnbr(const char *);
int	my_is_num(char *);
void	free_wordtab(char **);
void	my_putchar(char);
void	my_putstr(char *);
void	*my_memset(char *, int, int);

#endif /* !LIB_H_ */
