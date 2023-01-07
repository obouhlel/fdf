/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_calcule.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:02:09 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 18:07:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_projection	*ft_calcule_projection(t_map *map, float **mp, \
										float x, float y)
{
	t_projection	*projection;
	t_projection	*new;
	t_matrice_3D	*tmp;

	projection = NULL;
	new = NULL;
	tmp = NULL;
	while (map)
	{
		tmp = map->mat_3d;
		while (tmp)
		{
			x = ((mp[0][0] * tmp->x) + \
			(mp[0][1] * tmp->y) + (mp[0][2] * tmp->z));
			y = ((mp[1][0] * tmp->x) + \
			(mp[1][1] * tmp->y) + (mp[1][2] * tmp->z));
			new = ft_new_matrice_2d(x, y);
			if (!new)
				return (FAIL);
			ft_projection_add_back(&projection, new);
			tmp = tmp->next;
		}
		map = map->next_line;
	}
	return (projection);
}
