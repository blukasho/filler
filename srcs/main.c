/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:48:53 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/15 13:03:39 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_filler		*filler_init(void)
{
	t_filler	*filler;

	if (!(filler = (t_filler *)malloc(sizeof(t_filler))))
		return (NULL);
	ft_bzero(filler, sizeof(t_filler));
	return (filler);
}

int				main(void)
{
	t_filler	*filler;

	if (!(filler = filler_init()))
		return (0);
	if (!filler_read(filler) && !filler_clear(filler))
		return (0);
	return (0);
}
