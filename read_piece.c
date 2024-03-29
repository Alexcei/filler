/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:50:00 by bpole             #+#    #+#             */
/*   Updated: 2019/12/04 22:50:34 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_coord_piece(t_fil *fil)
{
	int		i;

	i = 0;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->h_pie = ft_atoi(fil->line + i);
	while (fil->line[i] && ft_isdigit(fil->line[i]))
		i++;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->w_pie = ft_atoi(fil->line + i);
	if (fil->h_pie && fil->w_pie)
		return (1);
	return (0);
}

static int	creat_piece(t_fil *fil, int i)
{
	if ((int)ft_strlen(fil->line) != fil->w_pie)
		return (0);
	if (!(fil->pie[i] = ft_strdup(fil->line)))
		return (0);
	return (1);
}

void		ft_read_piece_fil(t_fil *fil)
{
	int		i;

	get_next_line(0, &fil->line);
	if (!fil->line || !ft_strnequ(fil->line, "Piece", 5))
		print_error();
	if (!get_coord_piece(fil))
		print_error();
	ft_strdel(&fil->line);
	if (!(fil->pie = (char**)ft_memalloc(sizeof(char*) * (fil->h_pie + 1))))
		print_error();
	i = 0;
	while (i < fil->h_pie)
	{
		get_next_line(0, &fil->line);
		if (!fil->line || !creat_piece(fil, i))
			print_error();
		ft_strdel(&fil->line);
		i++;
	}
}
