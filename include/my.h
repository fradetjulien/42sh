/*
** my.h for  in /home/fradet_j/PSU/PSU_2016_minishell2/include
** 
** Made by Julien Fradet
** Login   <fradet_j@epitech.net>
** 
** Started on  Wed Mar 22 10:15:23 2017 Julien Fradet
** Last update Sun May 21 11:07:36 2017 Julien
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
int	loop(char **, char **, char **, int);
int	unsetenv_fct(char ***, char **, char *);
int	cd_fct(char *, char **, char ***, int *);
int	cd_alone(char **);
int	builtins_fct(char ***, char **, char *, int *);
int	setenv_fct(char ***, char **, char *, int *);
int	tablen(char **);
int	exit_fct(char *, char **, int *);
int	exit_shell(char **, int, int *);
int	case_enter(char *);
int	signal_check(int, int *);
int	annexe(char *, char **);
int	n_bu(char **);
int	fct_global(char *, char **, char **);
int	execute(char *, char **, char **, int *);
int	execute_fct(char *, char **, char **, int *);
int	count_delimitor(char **);
int	cd_tiret(char ***, char *, int *);
int	permissions(char *, int *);
int	permissions_bis(char *, int *);
int	permissions_exec(char *, char **, int *);
int	a_path(char *, int *);
int	check_execution_bin(char *, char **, char **, int *);
int	echo(char **);
int	where(char **, char **, int *);
int	which(char **, char **, int *);
int	repeat(char **, char **, char **, int *);
void	check_isat();
void	env_fct(char **);
void	affi();
void	fct_quit(char *);
void	print_err(char **, int *);

#endif /* !MY_H_ */
