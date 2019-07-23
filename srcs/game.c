/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:58:31 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/23 14:01:07 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			filler_is_player(t_filler *filler, int x, int y)
{
	if (!filler->map[y] || !filler->map[y][x])
		return (0);
	if (filler->map[y][x] == filler->player_s1 ||
		filler->map[y][x] == filler->player_s1)
		return (1);
	return (0);
}

int			filler_try_set_piece(t_filler *filler, int start_x, int start_y)
{
	int		x;
	int		y;
	int		star;

	star = 0;
	y = 0;
	while (y < filler->piece_y)
	{
		x = 0;
		while (x < filler->piece_x)
		{
			if (filler->piece[y][x] == PIECE_SYMBOL &&
				filler_is_player(filler, start_x + x, start_y + y))
				++star;
			++x;
		}
		++y;
	}
	return ((star == 1 ? 1 : 0));
}

int			filler_get_result(t_filler *filler)
{
	int		x;
	int		y;

	y = 0;
	while (y < filler->map_y)
	{
		x = 0;
		while (x < filler->map_x)
		{
			if (filler_try_set_piece(filler, x, y))
			{
				filler->result_x = x;
				filler->result_y = y;
				return (1);
			}
			++x;
		}
		++y;
	}
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
