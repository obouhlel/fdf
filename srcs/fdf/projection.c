/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/03 18:47:41 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	*ft_id_mat_2d(t_vars *vars, t_map *map, t_matrice_2D *mat_2d)
{
	t_matrice_3D	*tmp;
	int				x;
	int				y;

	tmp = NULL;
	x = 0;
	y = 0;
	while (map)
	{
		tmp = map->mat_3d;
		while (tmp)
		{
			mat_2d->point[X] = x;
			mat_2d->point[Y] = y;
			x++;
			tmp = tmp->next;
		}
		y++;
		map = map->next_line;
	}
}

void	*ft_main_projection(t_vars *vars)
{
	double	**mp;
	double	x;
	double	y;

	x = 0;
	y = 0;
	mp = ft_matrice_projection();
	if (!mp)
		return (FAIL);
	vars->mat_2d = ft_calcule_projection(vars->map, mp, x, y);
	if (!vars->mat_2d)
		return (ft_mp_clear(mp), FAIL);
	ft_mp_clear(mp);
	return (SUCCESS);
}
