/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:01:57 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 13:21:29 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_id_projection(t_map *map, t_projection *projection)
{
	t_matrice_3D	*tmp;
	int				x;
	int				y;

	tmp = NULL;
	y = 1;
	while (map)
	{
		tmp = map->mat_3d;
		x = 1;
		while (tmp)
		{
			projection->point[X] = x;
			projection->point[Y] = y;
			x++;
			projection = projection->next;
			tmp = tmp->next;
		}
		y++;
		map = map->next_line;
	}
}
