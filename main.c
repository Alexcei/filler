#include "filler.h"

void	out_put_fil(t_fil fil)
{
	ft_printf("%d %d\n", fil.y_out, fil.x_out);
}

void	free_all_fil(t_fil *fil)
{
	if (fil->plat)
		ft_free_char_arr(&fil->plat);
	if (fil->pie)
		ft_free_char_arr(&fil->pie);
	if (fil->map)
		ft_free_int_arr(&fil->map, fil->h_plat);
}

int		main(void)
{
	t_fil	fil;

	ft_bzero(&fil, sizeof(fil));
	ft_read_fil(&fil);
	ft_thinker_fil(&fil);
	out_put_fil(fil);
	free_all_fil(&fil);
	return 0;
}