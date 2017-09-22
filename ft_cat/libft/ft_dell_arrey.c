
#include "libft.h"

void	ft_dell_arrey(char **av)
{
	int		i;

	i = -1;
	if (!av || !*av)
		return ;
	while (av[++i])
		ft_strdel(&av[i]);
	ft_strdel(av);
}

