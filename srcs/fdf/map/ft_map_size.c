/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:10:10 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 13:49:54 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

int	ft_map_size(t_map *map)
{
	int	size;

	size = 0;
	while (map)
	{
		size++;
		map = map->next_line;
	}
	return (size);
}
