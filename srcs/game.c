/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:58:31 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/26 17:38:28 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			filler_check_overflow(t_filler *filler, int x, int y)
{
	if (y + (filler->piece_y) - 1 > filler->map_y ||
		x + (filler->piece_x) - 1 > filler->map_x)
		return (1);
	return (0);
}

int			filler_is_hostile(t_filler *filler, int x, int y)
{
	if (filler->map[y][x] == filler->hostile_s1 ||
		filler->map[y][x] == filler->hostile_s2)
		return (1);
	return (0);
}

int			filler_is_player(t_filler *filler, int x, int y)
{
	if (filler->map[y][x] == filler->player_s1 ||
		filler->map[y][x] == filler->player_s2)
		return (1);
	return (0);
}

int			filler_get_result(t_filler *filler)
{
//	if (filler_set_top_left_corner(filler))
//		return (1);
//	if (filler_set_top_right_corner(filler))
//		return (1);
//	if (filler_set_lower_left_corner(filler))
//		return (1);
//	if (filler_set_lower_right_corner(filler))
//		return (1);
	if (filler->hostile_lm_y < filler->player_lm_y &&
		filler->hostile_lm_x <= filler->player_lm_x &&
		filler_set_top_left_corner(filler))
		return (1);
//	ft_printf("game.c:43\n");
	if (filler->hostile_lm_y - 4 <= filler->player_lm_y &&
		filler->hostile_lm_x >= filler->player_lm_x &&
		filler_set_top_right_corner(filler))
		return (1);
//	ft_printf("game.c:47\n");
	if (filler->hostile_lm_y >= filler->player_lm_y &&
		filler->hostile_lm_x <= filler->player_lm_x &&
		filler_set_lower_left_corner(filler))
		return (1);
//	ft_printf("game.c:51\n");
	if (filler->hostile_lm_y > filler->player_lm_y &&
		filler->hostile_lm_x >= filler->player_lm_x &&
		filler_set_lower_right_corner(filler))
		return (1);
//	ft_printf("game.c:55\n");
	return (0);
}

int			filler_game(t_filler *filler)
{
	int		game_on;

	game_on = 1;
	while (game_on)
	{
		if (!filler_read(filler))
			return (0);
		filler_get_result(filler);
		ft_printf("%d %d\n", filler->result_y, filler->result_x);
		filler_clear_map_piece(filler);
	}
	return (0);
}
