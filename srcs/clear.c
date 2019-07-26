/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:28:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/26 15:55:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		filler_clear_map_piece(t_filler *filler)
{
	if (filler && filler->map && !ft_str_del_arr(filler->map))
		filler->map = NULL;
	if (filler && filler->piece && !ft_str_del_arr(filler->piece))
		filler->piece = NULL;
	if (filler)
	{
		filler->map_y = 0;
		filler->map_x = 0;
		filler->piece_y = 0;
		filler->piece_x = 0;
		filler->result_x = 0;
		filler->result_y = 0;
	}
	return (0);
}

int		filler_clear(t_filler *filler)
{
	if (filler && filler->map)
		ft_str_del_arr(filler->map);
	if (filler && filler->piece)
		ft_str_del_arr(filler->piece);
	if (filler)
		free(filler);
	return (0);
}
