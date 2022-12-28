/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:05 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 13:34:49 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_map_add_back(t_map **map, t_map *new)
{
	if (!map && !new)
		return ;
	if (!*map)
	{
		(*map) = new;
		return ;
	}
	new->next_line = (*map);
	(*map) = new;
}
