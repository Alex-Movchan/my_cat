
#include "libft.h"

int		ft_len_arrey(char **arrey)
{
	int		i;

	i = -1;
	while (arrey[++i])
		;
	return (i);
}