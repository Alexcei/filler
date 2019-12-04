/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:52:28 by bpole             #+#    #+#             */
/*   Updated: 2019/12/04 22:52:43 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_thinker_fil(t_fil *fil)
{
	int		i;

	i = 1;
	if (!(ft_creat_heat_map(fil)))
		print_error();
	ft_put_players_on_heat_map(fil);
	while (ft_fill_heat_map(fil, i))
		i++;
	ft_search_solution_fil(fil);
}
