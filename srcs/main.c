/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:48:53 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/14 11:18:25 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			main(void)
{
	char	*buf;
	int		fd;

	fd = open("./out", O_RDWR);
	get_next_line(STDOUT_FILENO, &buf);
	ft_putendl_fd(buf, fd);
	return (0);
}
