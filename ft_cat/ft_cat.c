

#include "ft_cat.h"

void	ft_cat(t_args *args, char **name)
{
	int fd;
	int	i;

	if (!name || !*name)
		ft_write_file(0, args);;//return (standert_inpout(args, 0));
	i = -1;

	while (name[++i])
	{
		if (!search_in_dir(name[i]))
		{
			ft_printf("{fd}No file in direct %{fd}s\n", 2, 2, name[i]);
			return ;
		}
		if ((fd = open(name[i], O_RDONLY)) == -1)
		{
			ft_printf("{fd}Error opening %{fd}s\n", 2, 2, name[i]);
			return ;
		}//erore opening
		ft_write_file(fd, args);
		close(fd);
	}
}