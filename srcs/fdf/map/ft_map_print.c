/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:38:20 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/02 12:18:54 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static void	ft_matrice_print(t_map *map)
{
	t_matrice_3D	*tmp;

	tmp = NULL;
	while (map)
	{
		tmp = map->matrice;
		while (tmp)
		{
			ft_putstrnbr_fd("x = ", tmp->x, 1);
			ft_putstrnbr_fd("y = ", tmp->y, 1);
			ft_putstrnbr_fd("z = ", tmp->z, 1);
			tmp = tmp->next;
		}
		map = map->next_line;
	}
}

void	ft_map_print(t_map *map)
{
	int	i;

	if (!map)
		ft_putendl_fd("(null)", 1);
	ft_matrice_print(map);
	while (map)
	{
		i = 0;
		while (i < map->nb_col)
		{
			ft_putnbr_fd(map->line[i], 1);
			ft_putstr_fd("  ", 1);
			i++;
		}
		ft_putstr_fd("\tLINE ID = ", 1);
		ft_putnbr_fd(map->id_line, 1);
		ft_putstr_fd("  NB LINE = ", 1);
		ft_putnbr_fd(map->nb_line, 1);
		ft_putstr_fd("  NB COL = ", 1);
		ft_putnbr_fd(map->nb_col, 1);
		ft_putchar_fd('\n', 1);
		map = map->next_line;
	}
}
