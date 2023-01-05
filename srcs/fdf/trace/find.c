/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:16:41 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/05 11:48:53 by obouhlel         ###   ########.fr       */
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

void	ft_init_find(t_point *find)
{
	int		i;
	int		j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			find[i].a[j] = 0;
			j++;
		}
		i++;
	}
}

t_point	*ft_next_point(t_point point, t_matrice_2D *mat_2d, t_point find[2])
{
	ft_init_find(find);
	while (mat_2d)
	{
		if (mat_2d->point[X] == (point.a[X] + 1) \
			&& mat_2d->point[Y] == point.a[Y])
		{
			find[X].a[X] = mat_2d->x;
			find[X].a[Y] = mat_2d->y;
		}
		if (mat_2d->point[Y] == (point.a[Y] + 1) \
			&& mat_2d->point[X] == point.a[X])
		{
			find[Y].a[X] = mat_2d->x;
			find[Y].a[Y] = mat_2d->y;
		}
		mat_2d = mat_2d->next;
	}
	return (find);
}
