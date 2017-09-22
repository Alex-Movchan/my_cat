
#include <dirent.h>
#include "ft_cat.h"

static char	*encript_dirname(char *src)
{
	char	*str;
	int		len;

	if (!ft_strchr(src, '/'))
		return (ft_strdup("."));
	len = (int)ft_strlen(src);
	while (--len && src[len] != '/')
		;
	str = ft_strndup(src, len);
	return (str);
}

static char	*encript_filename(char *src)
{
	char	*name;
	int		i;
	int		j;

	if (!ft_strchr(src, '/'))
		return (src);
	i = (int)ft_strlen(src);
	j = 0;
	while (--i && src[i] != '/')
		j++;
	name = (char*)malloc(sizeof(char) * j);
	j = -1;
	while (src[++i])
		name[++j] = src[i];
	name[++j] = '\0';
	return (name);
}

static void	end_search(char **s1, char **s2, char *s)
{
	ft_strdel(s1);
	if (ft_strchr(s, '/'))
		ft_strdel(s2);
}

int		search_in_dir(char *name_file)
{
	char			*dir_name;
	struct dirent	*dir;
	DIR				*ptr;
	char			*file;

	dir_name = encript_dirname(name_file);
	file = encript_filename(name_file);
	if (!(ptr = opendir(dir_name)))
	{
		end_search(&dir_name, &file, name_file);
		return (0);
	}
	while ((dir = readdir(ptr)))
	{
		if (!ft_strcmp(dir->d_name, file))
		{
			closedir(ptr);
			end_search(&dir_name, &file, name_file);
			return (1);
		}
	}
	closedir(ptr);
	end_search(&dir_name, &file, name_file);
	return (0);
}