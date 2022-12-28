/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:05:26 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 13:53:03 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_map	*ft_map_last(t_map *map)
{
	if (!map)
		return (NULL);
	while (map && map->next_line)
		map = map->next_line;
	return (map);
}
