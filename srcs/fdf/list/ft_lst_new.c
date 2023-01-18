/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:57:42 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 06:05:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_list	*ft_lst_new(t_map *map)
{
	t_list	*new;

	new = NULL;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->map = map;
	new->proj = NULL;
	new->pixel = NULL;
	new->line_right = ft_init_line();
	new->line_down = ft_init_line();
	new->next = NULL;
	return (new);
}

t_line	ft_init_line(void)
{
	t_line	line;

	line.start[X] = -1;
	line.start[Y] = -1;
	line.stop[X] = -1;
	line.stop[Y] = -1;
	line.color = 0;
	return (line);
}

t_map	*ft_new_map(int x, int y, int z, int color)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->x = x;
	map->y = y;
	map->z = z;
	map->color = color;
	return (map);
}

t_proj	*ft_new_proj(float x, float y)
{
	t_proj	*proj;

	proj = (t_proj *)malloc(sizeof(t_proj));
	if (!proj)
		return (NULL);
	proj->x = x;
	proj->y = y;
	return (proj);
}

t_pixel	*ft_new_pixel(int x, int y, int color)
{
	t_pixel	*pixel;

	pixel = (t_pixel *)malloc(sizeof(t_pixel));
	if (!pixel)
		return (NULL);
	pixel->x = x;
	pixel->y = y;
	pixel->color = color;
	return (pixel);
}
