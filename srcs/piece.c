/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:30:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/28 18:04:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			filler_get_minimal_piece_y(t_filler *filler)
{
	char	*tmp;
	char	**piece;

	while (!ft_strstr(*(filler->piece), "*"))
	{
		piece = filler->piece;
		tmp = *piece;
		ft_strdel(&tmp);
		--(filler->piece_y);
		++(filler->piece_delete_y);
		while (*piece)
		{
			*piece = *(piece + 1);
			if (*piece)
				++piece;
		}
	}
	piece = filler->piece;
	while (piece[(filler->piece_y) - 1] &&
		!ft_strstr(piece[(filler->piece_y) - 1], "*"))
	{
		ft_strdel(&piece[(filler->piece_y) - 1]);
		--(filler->piece_y);
	}
	return (0);
}

int			filler_get_minimal_piece_x(t_filler *filler)
{
	char	**piece;
	int		y;

	piece = filler->piece;
	while (filler_check_empty_column(piece, 0))
	{
		y = -1;
		++(filler->piece_delete_x);
		filler->piece_x = ft_strlen(*piece);
		while (piece[++y])
			ft_memmove(piece[y], (piece[y]) + 1, ft_strlen(piece[y] + 1) + 1);
	}
	while (filler_check_empty_column(piece, (filler->piece_x) - 1))
	{
		y = 0;
		while (piece[y])
		{
			piece[y][(filler->piece_x) - 1] = '\0';
			++y;
		}
		--(filler->piece_x);
		piece = filler->piece;
	}
	return (0);
}

int			filler_get_minimal_piece(t_filler *filler)
{
	filler_get_minimal_piece_y(filler);
	filler_get_minimal_piece_x(filler);
	return (1);
}

int			filler_get_piece(t_filler *filler)
{
	int		piece_y;
	char	*buf;

	piece_y = 0;
	if (!(filler->piece = (char **)malloc((filler->piece_y + 1) * sizeof(char *))))
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
