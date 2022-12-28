/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:05:08 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 15:05:12 by obouhlel         ###   ########.fr       */
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
