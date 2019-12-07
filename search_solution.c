/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 23:15:38 by bpole             #+#    #+#             */
/*   Updated: 2019/12/07 16:13:06 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_insert(t_fil *fil, int h, int w)
{
	if (h > fil->h_plat_tmp || w > fil->w_plat_tmp ||
		fil->h_plat - fil->h_plat_tmp < fil->h_pie - h ||
		fil->w_plat - fil->w_plat_tmp < fil->w_pie - w)
		return (0);
	return (1);
}

static int		chick_intersec(t_fil *fil, int h_start, int w_start)
{
	int			w;
	int			h;
	int			intersec;

	intersec = 0;
	h = 0;
	while (h < fil->h_pie)
	{
		w = 0;
		while (w < fil->w_pie)
		{
			if (fil->pie[h][w] == '*' &&
					fil->map[h + h_start][w + w_start] == 1)
				return (0);
			if (fil->pie[h][w] == '*' &&
			ft_is_i_fil(fil, fil->plat[h + h_start][w + w_start]))
				intersec++;
			if (intersec > 1)
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

static int		count_score(t_fil *fil, int h_start, int w_start)
{
	int			w;
	int			h;
	int			score;

	score = 0;
	h = 0;
	while (h < fil->h_pie)
	{
		w = 0;
		while (w < fil->w_pie)
		{
			if (fil->pie[h][w] == '*')
				score += fil->map[h + h_start][w + w_start];
			w++;
		}
		h++;
	}
	return (score);
}

static void		search_position_pie(t_fil *fil)
{
	int			score;

	fil->score = INT_MAX;
	fil->h_pie_tmp = -1;
	while (++fil->h_pie_tmp < fil->h_pie)
	{
		fil->w_pie_tmp = -1;
		while (++fil->w_pie_tmp < fil->w_pie)
		{
			if (fil->pie[fil->h_pie_tmp][fil->w_pie_tmp] == '*' &&
			check_insert(fil, fil->h_pie_tmp, fil->w_pie_tmp) &&
			chick_intersec(fil, fil->h_plat_tmp - fil->h_pie_tmp,
					fil->w_plat_tmp - fil->w_pie_tmp) &&
					(score = count_score(fil, fil->h_plat_tmp -
					fil->h_pie_tmp, fil->w_plat_tmp -
					fil->w_pie_tmp)) < fil->score)
			{
				fil->score = score;
				fil->w_fil = fil->w_pie_tmp;
				fil->h_fil = fil->h_pie_tmp;
				if (fil->count_enemy == fil->last_count_enemy)
					return ;
			}
		}
	}
}

void			ft_search_solution_fil(t_fil *fil)
{
	int			score;

	score = INT_MAX;
	fil->h_plat_tmp = -1;
	while (++fil->h_plat_tmp < fil->h_plat)
	{
		fil->w_plat_tmp = 0;
		while (fil->w_plat_tmp < fil->w_plat)
		{
			if (ft_is_i_fil(fil, fil->plat[fil->h_plat_tmp][fil->w_plat_tmp]))
			{
				search_position_pie(fil);
				if (score > fil->score)
				{
					fil->flag = 1;
					score = fil->score;
					fil->x_out = fil->w_plat_tmp - fil->w_fil;
					fil->y_out = fil->h_plat_tmp - fil->h_fil;
					if (fil->count_enemy == fil->last_count_enemy)
						return ;
				}
			}
			fil->w_plat_tmp++;
		}
	}
}
