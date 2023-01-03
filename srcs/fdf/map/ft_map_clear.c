/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:11:26 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/03 10:16:46 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static void	ft_matrice_clear(t_matrice_3D *matrice)
{
	t_matrice_3D	*tmp;

	tmp = NULL;
	while (matrice)
	{
		tmp = matrice->next;
		free(matrice);
		matrice = tmp;
	}
}

void	ft_map_clear(t_map *map)
{
	t_map	*tmp;

	tmp = NULL;
	while (map)
	{
		tmp = map->next_line;
		free(map->line);
		ft_matrice_clear(map->mat_3d);
		free(map);
		map = tmp;
	}
}
