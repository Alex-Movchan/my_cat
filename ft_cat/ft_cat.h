
#ifndef FT_CAT_H
#define FT_CAT_H

#include "libft/libft.h"
#include <fcntl.h>

typedef struct	s_args
{
	int			e; //еквівалент -vE ?  показувати $ наприкінці кожного рядка
	int			n; //кількість усіх рядків виводу
	int			b; // кількість непорожніх рядків виводу
	int			s;//не більше ніж один порожній рядок
	int 		help; //--help     показати цю довідку та вийти
}				t_args;

char			**record_args(t_args **arg, int len, char **av, char **name_file);
void			ft_cat(t_args *args, char **name);
void			ft_write_file(int fd, t_args *args);
int				ft_cat_help();
int				search_in_dir(char *name_file);

#endif