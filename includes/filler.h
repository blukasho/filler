/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:43:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/19 11:41:39 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <ft_printf.h>
# include <fcntl.h>

typedef struct	s_filler
{
	char		player;

	char		**map;
	int			map_x;
	int			map_y;

	char		**piece;
	int			piece_x;
	int			piece_y;

}				t_filler;

int			filler_clear(t_filler *filler);
int			filler_clear_map_piece(t_filler *filler);
t_filler	*filler_init(void);
int			filler_read(t_filler *filler);
char		**filler_realloc(char **arr, char *str);
char		*filler_get_correct_line(char *line);
int			filler_get_player(t_filler *filler);
int			filler_get_map_param(t_filler *filler);
int			filler_get_map(t_filler *filler);
int			filler_get_piece_param(t_filler *filler);
int			filler_get_piece(t_filler *filler);
int			filler_game(t_filler *filler);

#endif
