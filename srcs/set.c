/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 08:21:25 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/28 18:52:01 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			filler_try_set_piece(t_filler *filler, int start_x, int start_y)
{
	int		x;
	int		y;
	int		star;

	star = 0;
	y = -1;
	while (++y < filler->piece_y)
	{
		if (start_y + y > filler->map_y - 1)
			return (0);
		x = -1;
		while (++x < filler->piece_x)
			if (filler->piece[y][x] == '*' && start_x + x > filler->map_x)
				return (0);
			else if (start_x + x < filler->map_x)
			{
				if (filler->piece[y][x] == '*' &&
					filler_is_hostile(filler, start_x + x, start_y + y))
					return (0);
				if (filler->piece[y][x] == '*' &&
					filler_is_player(filler, start_x + x, start_y + y))
					++star;
			}
	}
	return ((star == 1 ? 1 : 0));
}

int			filler_set_top_left_corner(t_filler *filler)
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

int		filler_set_top_right_corner(t_filler *filler)
{
	int		x;
	int		y;

	y = 0;
	while (y < filler->map_y)
	{
		x = (filler->map_x) - 1;
		while (x >= 0)
		{
			if (filler_try_set_piece(filler, x, y))
			{
				filler->result_x = x;
				filler->result_y = y;
				return (1);
			}
			--x;
		}
		++y;
	}
	return (0);
}

int		filler_set_lower_left_corner(t_filler *filler)
{
	int		x;
	int		y;

	y = (filler->map_y) - 1;
	while (y >= 0)
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
		--y;
	}
	return (0);
}

int		filler_set_lower_right_corner(t_filler *filler)
{
	int		x;
	int		y;

	y = filler->map_y - 1;
	while (y >= 0)
	{
		x = filler->map_x;
		while (x >= 0)
		{
			if (filler_try_set_piece(filler, x, y))
			{
				filler->result_x = x;
				filler->result_y = y;
				return (1);
			}
			--x;
		}
		--y;
	}
	return (0);
}
