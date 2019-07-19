/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:58:31 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/19 12:36:35 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			filler_game(t_filler *filler)
{
	int		game_on;

	game_on = 1;
	while (game_on)
	{
		if (!filler_read(filler))
			game_on = 0;
		filler_clear_map_piece(filler);
	}
	return (0);
}
