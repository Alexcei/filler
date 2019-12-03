#include "filler.h"

void			print_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void			ft_free_char_arr(char ***arr)
{
	int			i;

	i = 0;
	if (*arr)
	{
		while ((*arr)[i])
			ft_strdel(&((*arr)[i++]));
		free(*arr);
		*arr = NULL;
	}
}

void			ft_free_int_arr(int ***arr, int h)
{
	int			i;

	i = 0;
	if (*arr)
	{
		while (i < h)
			ft_memdel((void*)&((*arr)[i++]));
		free(*arr);
		*arr = NULL;
	}
}

int		ft_is_enemy_fil(t_fil *fil, char c)
{
	if (fil->n_play == 1)
	{
		if (c == 'x' || c == 'X')
			return (1);
	}
	if (fil->n_play == 2)
	{
		if (c == 'o' || c == 'O')
			return (1);
	}
	return (0);
}

int		ft_is_i_fil(t_fil *fil, char c)
{
	if (fil->n_play == 1)
	{
		if (c == 'o' || c == 'O')
			return (1);
	}
	if (fil->n_play == 2)
	{
		if (c == 'x' || c == 'X')
			return (1);
	}
	return (0);
}