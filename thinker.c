#include "filler.h"

void	print_heat_map(t_fil *fil)
{
	int		w;
	int 	h;

	h = 0;
	while (h < fil->h_plat)
	{
		w = 0;
		while (w < fil->w_plat)
		{
			ft_printf("%2d ", fil->map[h][w]);
			w++;
		}
		ft_printf("\n");
		h++;
	}
}

void	ft_thinker_fil(t_fil *fil)
{
	int 	i;

	i = 1;
	if (!(ft_creat_heat_map(fil)))
		print_error();
	ft_put_players_on_heat_map(fil);
	while (ft_fill_heat_map(fil, i))
		i++;
	ft_search_solution_fil(fil);
	//print_heat_map(fil);
}