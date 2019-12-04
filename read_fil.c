/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:48:36 by bpole             #+#    #+#             */
/*   Updated: 2019/12/04 22:49:54 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_coord_plat(t_fil *fil)
{
	int			i;

	i = 0;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->h_plat = ft_atoi(fil->line + i);
	while (fil->line[i] && ft_isdigit(fil->line[i]))
		i++;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->w_plat = ft_atoi(fil->line + i);
	if (fil->h_plat && fil->w_plat)
		return (1);
	return (0);
}

static int		creat_plateau(t_fil *fil, int i)
{
	char		**arr;

	if (i == 0)
		return (1);
	if (!(arr = ft_strsplit(fil->line, ' ')))
		return (0);
	if (!arr[1] || ((int)ft_strlen(arr[1]) != fil->w_plat))
		return (0);
	if (!(fil->plat[i - 1] = ft_strdup(arr[1])))
		return (0);
	ft_free_char_arr(&arr);
	return (1);
}

static void		read_plateau(t_fil *fil)
{
	int			i;

	get_next_line(0, &fil->line);
	if (!fil->line || !ft_strnequ(fil->line, "Plateau", 7))
		print_error();
	if (!get_coord_plat(fil))
		print_error();
	ft_strdel(&fil->line);
	if (!(fil->plat = (char**)ft_memalloc(sizeof(char*) * (fil->h_plat + 1))))
		print_error();
	i = 0;
	while (i < fil->h_plat + 1)
	{
		get_next_line(0, &fil->line);
		if (!fil->line || !creat_plateau(fil, i))
			print_error();
		ft_strdel(&fil->line);
		i++;
	}
}

static void		read_player(t_fil *fil)
{
	get_next_line(0, &fil->line);
	if (!fil->line)
		print_error();
	if (ft_strnequ(fil->line, "$$$ exec p1", 11))
		fil->n_play = 1;
	else if (ft_strnequ(fil->line, "$$$ exec p2", 11))
		fil->n_play = 2;
	else
		print_error();
	ft_strdel(&fil->line);
}

void			ft_read_fil(t_fil *fil)
{
	if (!fil->n_play)
		read_player(fil);
	read_plateau(fil);
	ft_read_piece_fil(fil);
}
