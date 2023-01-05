/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_calcule.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:02:09 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/05 12:23:44 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static t_matrice_2D	*ft_new_matrice_2d(double x, double y)
{
	t_matrice_2D	*mat_2d;

	mat_2d = NULL;
	mat_2d = (t_matrice_2D *)malloc(sizeof(t_matrice_2D));
	if (!mat_2d)
		return (FAIL);
	mat_2d->point[X] = 0;
	mat_2d->point[Y] = 0;
	mat_2d->x = x;
	mat_2d->y = y;
	mat_2d->next = NULL;
	return (mat_2d);
}

static t_matrice_2D	*ft_mat_2d_last(t_matrice_2D *mat_2d)
{
	while (mat_2d && mat_2d->next)
		mat_2d = mat_2d->next;
	return (mat_2d);
}

static void	ft_mat_2d_add_back(t_matrice_2D **mat_2d, t_matrice_2D *new)
{
	t_matrice_2D	*last;

	last = NULL;
	if (!mat_2d | !new)
		return ;
	if (!*mat_2d)
	{
		(*mat_2d) = new;
		return ;
	}
	last = ft_mat_2d_last(*mat_2d);
	if (!last)
		return ;
	last->next = new;
}

void	ft_mat_2d_clear(t_matrice_2D *mat_2d)
{
	t_matrice_2D	*tmp;

	while (mat_2d)
	{
		tmp = mat_2d->next;
		free(mat_2d);
		mat_2d = tmp;
	}
	free(mat_2d);
}

t_matrice_2D	*ft_calcule_projection(t_map *map, double **mp, \
										double x, double y)
{
	t_matrice_2D	*mat_2d;
	t_matrice_2D	*new;
	t_matrice_3D	*tmp;

	mat_2d = NULL;
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
			ft_mat_2d_add_back(&mat_2d, new);
			tmp = tmp->next;
		}
		map = map->next_line;
	}
	return (mat_2d);
}
