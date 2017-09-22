
#include "ft_cat.h"

static void		record_arguments(t_args **arg, char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == 's')
			(*arg)->s = 1;
		else if (str[i] == 'e')
			(*arg)->e = 1;
		else if (str[i] == 'b')
			(*arg)->b = 1;
		else if (str[i] == 'n')
			(*arg)->n = 1;
		else
			break ;
	}
	(*arg)->n = (*arg)->b == 1 ? 0 : (*arg)->n;
}

static char		**ft_realokarrey(char **s1, char **s2, char *str)
{
	int		i;

	i = -1;
	s1 = (char**)malloc(sizeof(char*) * (ft_len_arrey(s2) + 1));
	while (s2[++i])
		s1[i] = s2[i];
	s1[++i] = ft_strdup(str);
	s1[++i] = NULL;
	ft_dell_arrey(s2);
	return (s1);
}

static char		**record_name(char *str, char **name)
{
	if (!name)
	{
		name = (char**)malloc(sizeof(char*) * 2);
		name[0] = ft_strdup(str);
		name[1] = NULL;
		return (name);
	}
	else
		return (ft_realokarrey(NULL, name, str));
}

char		**record_args(t_args **arg, int len, char **av, char **name_file)
{
	int		i;

	i = 0;
	while (++i < len)
	{
		if (!ft_strcmp("--help", av[i]))
		{
			(*arg)->help = 1;
			break ;
		}
		else if (av[i][0] == '-')
			record_arguments(arg, av[i]);
		else
			name_file = record_name(av[i], name_file);
	}
	return (name_file);
}