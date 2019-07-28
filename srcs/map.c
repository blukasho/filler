/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:12:59 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/28 18:03:28 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			filler_get_last_move_hostile(t_filler *filler)
{
	int		y;
	int		x;

	y = 0;
	while (y < filler->map_y)
	{
		x = 0;
		while (x < filler->map_x)
		{
			if (filler->map[y][x] == filler->hostile_s2)
			{
				filler->hostile_lm_y = y;
				filler->hostile_lm_x = x;
			}
			++x;
		}
		++y;
	}
	return (1);
}

int			filler_get_last_move_players(t_filler *filler)
{
	int		x;
	int		y;

	y = 0;
	while (y < filler->map_y)
	{
		x = 0;
		while (x < filler->map_x)
		{
			if (filler->map[y][x] == filler->player_s1)
			{
				filler->player_lm_y = y;
				filler->player_lm_x = x;
			}
			if (filler->map[y][x] == filler->hostile_s1)
			{
				filler->hostile_lm_y = y;
				filler->hostile_lm_x = x;
			}
			++x;
		}
		++y;
	}
	filler_get_last_move_hostile(filler);
	return (1);
}

int			filler_get_map_param(t_filler *filler)
{
	char	*buf;
	char	*tmp;

	if (!(buf = filler_get_line()))
		return (0);
	if (!ft_strstr(buf, "Plateau ") && !ft_strdel(&buf))
		return (0);
	tmp = buf;
	buf = ft_strstr(buf, " ") + 1;
	if ((!*buf || !(filler->map_y = ft_atoi(buf))) && !ft_strdel(&tmp))
		return (0);
	while (*buf && ft_isdigit(*buf))
		++buf;
	if ((!*buf || !(filler->map_x = ft_atoi(buf))) && !ft_strdel(&tmp))
		return (0);
	if (!(filler->map = (char **)malloc(((filler->map_y) + 1) * sizeof(char *))))
		return (filler_clear(filler));
	*(filler->map) = NULL;
	ft_strdel(&tmp);
	return (1);
}

char		*filler_get_correct_line(char *line)
{
	ft_memmove(line, ft_strstr(line, " ") + 1, ft_strlen(ft_strstr(line, " ")));
	return (line);
}

int			filler_get_map(t_filler *filler)
{
	int		map_y;
	char	*buf;

	if (!(buf = filler_get_line()))
		return (0);
	ft_strdel(&buf);
	map_y = 0;
	while (map_y < (filler->map_y) && (buf = filler_get_line()))
		filler->map[map_y++] = filler_get_correct_line(buf);
	filler->map[map_y] = NULL;
	return (1);
}
