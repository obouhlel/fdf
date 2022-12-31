/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_nb_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:59:07 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/31 15:08:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_map_init_nb_line(t_map *map)
{
	const int	nb_line = ft_map_size(map);

	while (map)
	{
		map->nb_line = nb_line;
		map = map->next_line;
	}
}
