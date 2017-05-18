/*
** my.h for  in /home/fradet_j/PSU/PSU_2016_minishell2/include
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 10:15:23 2017 Julien Fradet
** Last update Thu May 18 06:21:36 2017 Julien
*/

#ifndef MY_H_
# define MY_H_

# define UNUSED __attribute__((unused))

char	**path_oldpwd(char **, char *);
char	**get_pwd(char **);
char	*get_env(char **, char *);
char	*my_lessconcat(char *, char);
char	*my_access(char **, char *);
char	*get_oldpwd(char **);
int	unsetenv_fct(char ***, char **, char *);
int	cd_fct(char *, char **, char ***, int *);
int	builtins_fct(char ***, char **, char *, int *);
int	setenv_fct(char ***, char **, char *, int *);
int	tablen(char **);
int	exit_fct(char *, char **, int *);
int	exit_shell(char **, int, int *);
int	case_enter(char *);
int	signal_check(int, int *);
int	annexe(char *, char **);
int	not_builtins(char **);
int	fct_global(char *, char **, char **);
int	execute(char *, char **, char **, int *);
int	count_delimitor(char *);
int	cd_tiret(char ***, char *, int *);
int	permissions(char *, int *);
int	permissions_bis(char *, int *);
int	absolute_path(char *, int *);
void	check_isat();
void	env_fct(char **);
void	affi();
void	fct_quit(char *);
void	print_error(char **, int *);

#endif /* !MY_H_ */
