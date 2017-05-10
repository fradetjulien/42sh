/*
** epur.c for  in /home/lenoir
** 
** Made by LENOIR
** Login   <guillaume.lenoir@epitech.eu>
** 
** Started on  Thu Apr  6 02:53:05 2017 LENOIR
** Last update Fri Apr  7 21:03:48 2017 LENOIR
*/

char	*dec_left(char *c, int i)
{
  while (c[i])
    {
      c[i] = c[i + 1];
      if (c[i])
	i++;
    }
  return (c);
}

char	*epur_around(char *line, int *i)
{
  int	count;

  count = 0;
  while (line [*i + 1] && line[*i + 1] == ' ')
    {
      count++;
      line = dec_left(line, *i + 1);
    }
  while (*i - 1 > -1 && line[*i - 1] && line[*i - 1] == ' ')
    {
      count++;
      line = dec_left(line, *i - 1);
    }
  *i -= count;
  return (line);
  
}

char	*epur_line(char *line)
{
  int	i;

  i = 0;
  while (line[0] && line[0] == ' ')
    line++;
  while(line[i])
    {
      if (line[i] == ' ')
	{
	  while (line[i + 1] == ' ')
	    line = dec_left(line, i);
	}
      if (line[i] == '>' || line[i] == '<' ||
	  line[i] == '|' || line[i] == ';')
	line = epur_around(line, &i);
      i++;
    }
  return (line);
}

