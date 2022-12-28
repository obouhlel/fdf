/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:05:26 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 15:03:34 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_map	*ft_map_last(t_map *map)
{
	if (!map)
		return (FAIL);
	while (map && map->next_line)
		map = map->next_line;
	return (map);
}
