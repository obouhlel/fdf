/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:16:41 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/04 14:54:59 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_id_mat_2d(t_map *map, t_matrice_2D *mat_2d)
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
			mat_2d->point[X] = x;
			mat_2d->point[Y] = y;
			x++;
			mat_2d = mat_2d->next;
			tmp = tmp->next;
		}
		y++;
		map = map->next_line;
	}
}
