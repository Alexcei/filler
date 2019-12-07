/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:55:52 by bpole             #+#    #+#             */
/*   Updated: 2019/12/07 15:36:54 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void			print_error(t_fil *fil, char *message)
{
	fil->read = 1;
	ft_putendl_fd(message, 0);
}

void			ft_free_char_arr(char ***arr)
{
	int			i;

	i = 0;
	if (*arr)
	{
		while ((*arr)[i])
			ft_strdel(&((*arr)[i++]));
		free(*arr);
		*arr = NULL;
	}
}

int				ft_word_count(char const *str, char c)
{
	int			tr;
	int			res;

	tr = 0;
	res = 0;
	while (*str)
	{
		if (*str != c && tr == 0)
			res++;
		tr = (*str++ != c ? 1 : 0);
	}
	return (res);
}

void			ft_free_int_arr(int ***arr, int h)
{
	int			i;

	i = 0;
	if (*arr)
	{
		while (i < h)
			ft_memdel((void*)&((*arr)[i++]));
		free(*arr);
		*arr = NULL;
	}
}

int				ft_is_enemy_fil(t_fil *fil, char c)
{
	if (fil->n_play == 2)
	{
		if (c == 'x' || c == 'X')
			return (1);
	}
	if (fil->n_play == 1)
	{
		if (c == 'o' || c == 'O')
			return (1);
	}
	return (0);
}
