/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:48:00 by bpole             #+#    #+#             */
/*   Updated: 2019/12/04 22:59:45 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		out_put_fil(t_fil *fil)
{
	if (fil->flag)
	{
		fil->flag = 0;
		ft_printf("%d %d\n", fil->y_out, fil->x_out);
		fil->y_out = 0;
		fil->x_out = 0;
	}
	else
		ft_printf("%d %d\n", 0, 0);
}

void		free_all_fil(t_fil *fil)
{
	if (fil->plat)
		ft_free_char_arr(&fil->plat);
	if (fil->pie)
		ft_free_char_arr(&fil->pie);
	if (fil->map)
		ft_free_int_arr(&fil->map, fil->h_plat);
}

int			main(void)
{
	t_fil	fil;

	ft_bzero(&fil, sizeof(fil));
	while (21)
	{
		ft_read_fil(&fil);
		ft_thinker_fil(&fil);
		out_put_fil(&fil);
		free_all_fil(&fil);
	}
	return (0);
}
