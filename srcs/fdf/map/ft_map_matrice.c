/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:38:16 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/03 10:15:16 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static t_matrice_3D	*ft_new_matrice(int x, int y, int z)
{
	t_matrice_3D	*matrice;

	matrice = (t_matrice_3D *)malloc(sizeof(t_matrice_3D));
	if (!matrice)
		return (NULL);
	matrice->x = x;
	matrice->y = y;
	matrice->z = z;
	matrice->next = NULL;
	return (matrice);
}

static t_matrice_3D	*ft_matrice_last(t_matrice_3D *matrice)
{
	while (matrice && matrice->next)
		matrice = matrice->next;
	return (matrice);
}

static void	ft_matrice_add_back(t_matrice_3D **matrice, t_matrice_3D *new)
{
	t_matrice_3D	*last;

	last = NULL;
	if (!matrice | !new)
		return ;
	if (!*matrice)
	{
		(*matrice) = new;
		return ;
	}
	last = ft_matrice_last(*matrice);
	if (!last)
		return ;
	last->next = new;
}

t_matrice_3D	*ft_map_matrice(int *line, int nb_col, int id_line)
{
	t_matrice_3D	*mat_3d;
	t_matrice_3D	*tmp;
	int				i;

	mat_3d = NULL;
	i = 0;
	while (i < nb_col)
	{
		tmp = ft_new_matrice((i + 1), id_line, line[i]);
		if (!tmp)
			return (NULL);
		ft_matrice_add_back(&mat_3d, tmp);
		i++;
	}
	return (mat_3d);
}
