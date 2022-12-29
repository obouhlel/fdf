/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:38:20 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/29 21:24:20 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_map_print(t_map *map)
{
	int	i;

	if (!map)
		ft_putendl_fd("(null)", 1);
	while (map)
	{
		i = 0;
		while (i < map->nb_col)
		{
			ft_putnbr_fd(map->line[i], 1);
			ft_putstr_fd("  ", 1);
			i++;
		}
		ft_putchar_fd('\n', 1);
		map = map->next_line;
	}
}
