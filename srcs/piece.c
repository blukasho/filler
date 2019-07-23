/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:30:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/23 15:29:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			filler_get_piece(t_filler *filler)
{
	int		piece_y;
	char	*buf;

	piece_y = 0;
	if (!(filler->piece = (char **)malloc((filler->piece_y + 1) *
		sizeof(char *))))
		return (0);
	while (piece_y < filler->piece_y && (buf = filler_get_line()))
		(filler->piece)[piece_y++] = buf;
	filler->piece[piece_y] = NULL;
	return (1);
}

int			filler_get_piece_param(t_filler *filler)
{
	char	*buf;
	char	*tmp;

	if (!(buf = filler_get_line()))
		return (0);
	if (!ft_strstr(buf, "Piece ") && !ft_strdel(&buf))
		return (0);
	tmp = buf;
	buf += ft_strlen("Piece ");
	if (!(filler->piece_y = ft_atoi(buf)) && !ft_strdel(&tmp))
		return (0);
	if (!(buf = ft_strstr(buf, " ")))
		return (0);
	if (!(filler->piece_x = ft_atoi(buf)) && !ft_strdel(&tmp))
		return (0);
	ft_strdel(&tmp);
	return (1);
}
