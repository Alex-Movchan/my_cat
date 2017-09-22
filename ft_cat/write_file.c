
#include "ft_cat.h"

static void	print_line(t_args *args, char *line, int nbr)
{
	if (args->e)
	{
		if (args->b && line[0] != '\0')
			ft_printf("% 5d %s$", nbr, line);
		else if (args->n)
			ft_printf("% 5d %s$", nbr, line);
		else
			ft_printf("%s$");
	}
	else if (args->b && line[0] != '\0')
		ft_printf("% 5d %s", nbr, line);
	else if (args->n)
		ft_printf("% 5d %s", nbr, line);
	else
		ft_printf("%s");

}

void	ft_write_file(int fd, t_args *args)
{
	char	*line;
	char	*src;
	int 	nbr;

	nbr = 0;
	src = NULL;
	while (get_next_line(fd, &line))
	{
		if (args->b && line[0] != '\0')
			nbr++;
		else if (args->n)
			nbr++;
		if (args->s && src && src[0] == '\0' && line[0] == '\0')
			continue ;
		ft_strdel(&src);
		src = line;
		print_line(args, line, nbr);
		ft_printf("\n");
	}
	ft_strdel(&src);
	ft_strdel(&line);
}