#include "filler.h"

static int 		get_coord_plat(t_fil *fil)
{
	int 	i;

	i = 0;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->heigth = ft_atoi(fil->line + i);
	while (fil->line[i] && ft_isdigit(fil->line[i]))
		i++;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->width = ft_atoi(fil->line + i);
	if (fil->heigth && fil->width)
		return (1);
	return (0);
}

static int 		creat_plateau(t_fil *fil, int i)
{
	char	**arr;

	if (i == 0)
		return (1);
	if (!(arr = ft_strsplit(fil->line, ' ')))
		return (0);
	if (!arr[1] || ((int)ft_strlen(arr[1]) != fil->width))
		return (0);
	if (!(fil->plat[i - 1] = ft_strdup(arr[1])))
		return (0);
	ft_free_char_arr(&arr);
	return (1);
}

static void		read_plateau(t_fil *fil)
{
	int 	i;

	get_next_line(0, &fil->line);
	if (!fil->line || !ft_strnequ(fil->line, "Plateau", 7))
		print_error("error");
	if (!get_coord_plat(fil))
		print_error("error");
	ft_strdel(&fil->line);
	if (!(fil->plat = (char**)ft_memalloc(sizeof(char*) * (fil->heigth + 1))))
		print_error("malloc error");
	i = 0;
	while (i < fil->heigth + 1)
	{
		get_next_line(0, &fil->line);
		if (!fil->line || !creat_plateau(fil, i))
			print_error("error");
		ft_strdel(&fil->line);
		i++;
	}
}

static void		read_player(t_fil *fil)
{
	get_next_line(0, &fil->line);
	if (!fil->line)
		print_error("error");
	if (ft_strnequ(fil->line, "$$$ exec p1", 11))
		fil->n_play = 1;
	else if (ft_strnequ(fil->line, "$$$ exec p2", 11))
		fil->n_play = 2;
	else
		print_error("error");
	ft_strdel(&fil->line);
}

void	ft_read_fil(t_fil *fil)
{
	read_player(fil);
	read_plateau(fil);
	ft_read_piece_fil(fil);
}