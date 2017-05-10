/*
** pipe.c for  in /home/lenoir/rendu/PSU_2015_minishell2
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Sat Apr  8 05:31:01 2017 LENOIR
** Last update Sat Apr  8 05:35:28 2017 LENOIR
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  int pipefd[2];
  int pid;
  int pid2;

  char *ll_args[] = {"ls", "-l", NULL};
  char *wc_args[] = {"wc", "-l", NULL};

  // make a pipe (fds go in pipefd[0] and pipefd[1])

  pipe(pipefd);
  pid = fork();
  if (pid == 0)
    {
      // child gets here and handles "wc -l"
      // replace standard input with input part of pipe
      dup2(pipefd[0], 0);

      // close unused hald of pipe
      close(pipefd[1]);

      // execute wc -l
      execvp("wc", wc_args);
    }
  else
    {
      // parent gets here and handles "ls -l"
      // replace standard output with output part of pipe
      dup2(pipefd[1], 1);

      // close unused unput half of pipe
      close(pipefd[0]);

      // execute ls -l
      execvp("ls", ll_args);
    }

  return 0;
}
