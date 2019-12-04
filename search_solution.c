#include "filler.h"

static int	check_insert_pie_in_plat(t_fil *fil, int h, int w)
{
	if (h > fil->h_plat_tmp || w > fil->w_plat_tmp ||
		fil->h_plat - fil->h_plat_tmp < fil->h_pie - h ||
		fil->w_plat - fil->w_plat_tmp < fil->w_pie - w)
		return (0);
	return (1);
}

static int	chick_intersec(t_fil *fil, int h_start, int w_start)
{
	int		w;
	int 	h;
	int 	intersec;

	intersec = 0;
	h = 0;
	while (h < fil->h_pie)
	{
		w = 0;
		while (w < fil->w_pie)
		{
			if (fil->pie[h][w] == '*' && fil->map[h + h_start][w + w_start] == 1)
				return (0);
			if (fil->pie[h][w] == '*' && fil->map[h + h_start][w + w_start] == -1)
				intersec++;
			if (intersec > 1)
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

static int	count_score_head_map(t_fil *fil, int h_start, int w_start)
{
	int		w;
	int 	h;
	int 	score;

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

static int	search_position_pie(t_fil *fil)
{
	int 	score;

	fil->score = INT_MAX;
	fil->h_pie_tmp = 0;
	while (fil->h_pie_tmp < fil->h_pie)
	{
		fil->w_pie_tmp = 0;
		while (fil->w_pie_tmp < fil->w_pie)
		{
			if (fil->pie[fil->h_pie_tmp][fil->w_pie_tmp] == '*')
			{
				if (check_insert_pie_in_plat(fil, fil->h_pie_tmp, fil->w_pie_tmp) &&
				chick_intersec(fil, fil->h_plat_tmp - fil->h_pie_tmp, fil->w_plat_tmp - fil->w_pie_tmp))
					if ((score = count_score_head_map(fil, fil->h_plat_tmp - fil->h_pie_tmp, fil->w_plat_tmp - fil->w_pie_tmp)) < fil->score)
					{
						fil->score = score;
						fil->w_fil = fil->w_pie_tmp;
						fil->h_fil = fil->h_pie_tmp;
					}
			}
			fil->w_pie_tmp++;
		}
		fil->h_pie_tmp++;
	}
	return (score);
}

void		ft_search_solution_fil(t_fil *fil)
{
	int 	score;

	score = INT_MAX;
	fil->h_plat_tmp = 0;
	while (fil->h_plat_tmp < fil->h_plat)
	{
		fil->w_plat_tmp = 0;
		while (fil->w_plat_tmp < fil->w_plat)
		{
			if (fil->map[fil->h_plat_tmp][fil->w_plat_tmp] == -1)
			{
				search_position_pie(fil);
				if (score > fil->score)
				{
				score = fil->score;
				fil->x_out = fil->w_plat_tmp - fil->w_fil;
				fil->y_out = fil->h_plat_tmp - fil->h_fil;
				}
			}
			fil->w_plat_tmp++;
		}
		fil->h_plat_tmp++;
	}
}