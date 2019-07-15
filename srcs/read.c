/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:41:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/15 13:07:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

char		 **filler_realloc(char **arr, char *str)
{
	char	**tmp;
	int		i;

	if (!arr)
		arr = (char **)malloc(2 * sizeof(char *));
	else
	{
		tmp = arr;
		arr = (char **)malloc((ft_strlenarr(tmp) + 2) * sizeof(char *));
		i = -1;
		while (tmp[++i])
			arr[i] = tmp[i];
		arr[i++] = str;
		arr[i] = NULL;
		ft_str_del_arr(tmp);
		return (arr);
	}
	*arr = str;
	*(arr + 1) = NULL;
	return (arr);
}

int			filler_get_player(t_filler *filler, char *buf)
{
	if (!ft_strstr(buf, "$$$ exec "))
		return (0);
	if (ft_strstr(buf, "p1") && (filler->player = 'O'))
		return (1);
	if (ft_strstr(buf, "p2") && (filler->player = 'X'))
		return (1);
	return (0);
}

char		**filler_read(t_filler *filler)
{
	char	*buf;
	//
	int		fd;

	fd = open("./out", O_RDWR);
	if (fd == -1)
		ft_putendl_fd("ERROR", 2);
	//
	get_next_line(0, &buf);
	if (!buf || !filler_get_player(filler, buf))
		return ((char **)ft_strdel(&buf));
	ft_putendl_fd(buf, fd);//
	ft_strdel(&buf);
	get_next_line(0, &buf);//
	ft_putendl_fd(buf, fd);//
	ft_strdel(&buf);
	return (NULL);
}
