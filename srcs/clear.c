/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:28:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/16 08:44:51 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

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
