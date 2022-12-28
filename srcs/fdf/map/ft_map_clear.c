/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:11:26 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 13:49:08 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_map_clear(t_map *map)
{
	t_map	*tmp;

	tmp = NULL;
	while (map)
	{
		tmp = map->next_line;
		free(map->line);
		free(map);
		map = tmp;
	}
}
