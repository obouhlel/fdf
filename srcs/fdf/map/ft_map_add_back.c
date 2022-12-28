/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:02:14 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 13:34:15 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_map_add_back(t_map **map, t_map *new)
{
	t_map	*last;

	last = NULL;
	if (!map | !new)
		return ;
	if (!*map)
	{
		(*map) = new;
		return ;
	}
	last = ft_map_last(*map);
	if (!last)
		return ;
	last->next_line = new;
}
