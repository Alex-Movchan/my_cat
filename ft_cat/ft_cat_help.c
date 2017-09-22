
#include "ft_cat.h"

int		ft_cat_help()
{
	int	fd;
	char *line;

	fd = open("../help.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (0);
}