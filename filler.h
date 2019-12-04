#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct	s_fil
{
	char 		**plat;
	int 		w_plat;
	int 		h_plat;
	char 		**pie;
	int 		w_pie;
	int 		h_pie;
	int			n_play;
	int 		x_out;
	int 		y_out;
	char		*line;
	int 		**map;
	int 		score;
	int 		w_plat_tmp;
	int 		h_plat_tmp;
	int 		w_pie_tmp;
	int 		h_pie_tmp;
	int 		h_fil;
	int 		w_fil;
}				t_fil;

/*
*				head_map.c
*/
void			ft_put_players_on_heat_map(t_fil *fil);
int				ft_creat_heat_map(t_fil *fil);
int				ft_fill_heat_map(t_fil *fil, int i);

/*
* 				read_fil.c
*/
void			ft_read_fil(t_fil *fil);

/*
* 				read_piece.c
*/
void			ft_read_piece_fil(t_fil *fil);

/*
* 				search_solution.c
*/
void			ft_search_solution_fil(t_fil *fil);

/*
* 				thinker.c
*/
void			ft_thinker_fil(t_fil *fil);

/*
* 				utils.c
*/
void			print_error(void);
void			ft_free_char_arr(char ***arr);
void			ft_free_int_arr(int ***arr, int h);
int				ft_is_enemy_fil(t_fil *fil, char c);
int				ft_is_i_fil(t_fil *fil, char c);

#endif