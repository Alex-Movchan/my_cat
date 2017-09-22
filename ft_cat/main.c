
#include "ft_cat.h"

static t_args	*init_args(t_args *arg)
{
	arg = (t_args*)malloc(sizeof(t_args));
	arg->s = 0;
	arg->b = 0;
	arg->e = 0;
	arg->n = 0;
	arg->help = 0;
	return (arg);
}

int		main(int ac, char **av)
{
	t_args	*args;
	char	**name;

	name = NULL;
	args = init_args(NULL);
	name =	record_args(&args, ac, av, name);
	if (args->help)
	{
		ft_dell_arrey(name);
		free(args);
		return (ft_cat_help());
	}
	ft_cat(args, name);
	ft_dell_arrey(name);
	free(args);
}