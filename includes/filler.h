/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:43:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/25 14:32:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <fcntl.h>
# define FILL_SYMBOL '.'
# define PIECE_SYMBOL '*'

typedef struct	s_filler
{
	char		player_s1;
	char		player_s2;
	char		hostile_s1;
	char		hostile_s2;
	char		**map;
	int			map_x;
	int			map_y;
	char		**piece;
	int			piece_x;
	int			piece_y;
	int			player_lm_x;
	int			player_lm_y;
	int			hostile_lm_x;
	int			hostile_lm_y;
	int			result_x;
	int			result_y;
}				t_filler;

int			filler_clear(t_filler *filler);
int			filler_clear_map_piece(t_filler *filler);
int			filler_read(t_filler *filler);
char		*filler_get_line(void);
char		**filler_realloc(char **arr, char *str);
char		*filler_get_correct_line(char *line);
int			filler_get_players(t_filler *filler);
int			filler_get_map_param(t_filler *filler);
int			filler_get_map(t_filler *filler);
int			filler_get_last_move_players(t_filler *filler);
int			filler_get_last_move_hostile(t_filler *filler);
int			filler_get_piece_param(t_filler *filler);
int			filler_get_piece(t_filler *filler);
int			filler_get_result(t_filler *filler);
int			filler_game(t_filler *filler);
int			filler_is_player(t_filler *filler, int x, int y);
int			filler_try_set_piece(t_filler *filler, int x, int y);
int			filler_set_top_left_corner(t_filler *filler);
int			filler_set_top_right_corner(t_filler *filler);
int			filler_set_lower_left_corner(t_filler *filler);
int			filler_set_lower_right_corner(t_filler *filler);

#endif
