/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:12:59 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/16 13:37:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			filler_get_map_param(t_filler *filler)
{
	char	*buf;
	char	*tmp;

	if (get_next_line(STDIN_FILENO, &buf) < 1)
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
	if (!(filler->map = ft_get_arr(filler->map_x, filler->map_y)))
			return (filler_clear(filler));
	ft_strdel(&tmp);
	return (1);
}

int			filler_get_map(t_filler *filler)
{
	char	*buf;
	//
	int		fd;

	fd = open("./out", O_RDWR);
	if (fd == -1)
		ft_putendl_fd("ERROR", 2);
	if (filler)
	{}
	//
	get_next_line(0, &buf);
	ft_strdel(&buf);
	get_next_line(0, &buf);
	ft_putendl_fd(buf, fd);//
	ft_strdel(&buf);
	return (0);
}
