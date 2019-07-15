/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:28:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/15 13:07:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	*filler_clear(t_filler *filler)
{
	if (filler && filler->map)
		ft_str_del_arr(filler->map);
	if (filler && filler->piece)
		ft_str_del_arr(filler->piece);
	if (filler)
		free(filler);
	return (NULL);
}
