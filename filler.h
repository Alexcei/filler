#ifndef FILLER_H
# define FILLER_H

# include "ft_printf/ft_printf.h"

typedef struct	s_fil
{
	char 		**plat;
	int 		width;
	int 		heigth;
	char 		**pie;
	int 		w;
	int 		h;
	int			n_play;
	int 		x_out;
	int 		y_out;
	char		*line;
	int 		**map;
	int 		score;
}				t_fil;

/*
 *
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
 * 				thinker.c
 */
void			ft_thinker_fil(t_fil *fil);

/*
 * 				utils.c
 */
void			print_error(char *message);
void			ft_free_char_arr(char ***arr);
void			ft_free_int_arr(int ***arr, int h);
int				ft_is_enemy_fil(t_fil *fil, char c);
int				ft_is_i_fil(t_fil *fil, char c);

#endif