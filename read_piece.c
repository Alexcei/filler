#include "filler.h"

static int 		get_coord_piece(t_fil *fil)
{
	int 	i;

	i = 0;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->h = ft_atoi(fil->line + i);
	while (fil->line[i] && ft_isdigit(fil->line[i]))
		i++;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->w = ft_atoi(fil->line + i);
	if (fil->h && fil->w)
		return (1);
	return (0);
}

static int 		creat_piece(t_fil *fil, int i)
{
	if ((int)ft_strlen(fil->line) != fil->w)
		return (0);
	if (!(fil->pie[i] = ft_strdup(fil->line)))
		return (0);
	return (1);
}

void		ft_read_piece_fil(t_fil *fil)
{
	int 	i;

	get_next_line(0, &fil->line);
	if (!fil->line || !ft_strnequ(fil->line, "Piece", 5))
		print_error("error");
	if (!get_coord_piece(fil))
		print_error("error");
	ft_strdel(&fil->line);
	if (!(fil->pie = (char**)ft_memalloc(sizeof(char*) * (fil->h + 1))))
		print_error("malloc error");
	i = 0;
	while (i < fil->h)
	{
		get_next_line(0, &fil->line);
		if (!fil->line || !creat_piece(fil, i))
			print_error("error");
		ft_strdel(&fil->line);
		i++;
	}
}