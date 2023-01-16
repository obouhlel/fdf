/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:08:57 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/16 12:36:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_find_x_max_map(t_list *lst, int y)
{
	int	x_max;

	x_max = 0;
	while (lst)
	{
		while (lst && lst->map->y == y)
		{
			if (x_max < lst->map->x)
				x_max = lst->map->x;
			lst = lst->next;
		}
		if (x_max > 0)
			return (x_max);
		lst = lst->next;
	}
	return (x_max);
}

void	ft_init_line(t_line *line)
{
	line->start[X] = -1;
	line->start[Y] = -1;
	line->stop[X] = -1;
	line->stop[Y] = -1;
}

void	ft_find_next_point_x(t_list *lst, t_line *line, int point[2])
{
	ft_init_line(line);
	while (lst)
	{
		if (point[X] == lst->map->x && point[Y] == lst->map->y)
		{
			line->start[X] = lst->pixel->x;
			line->start[Y] = lst->pixel->y;
			line->color = lst->pixel->color;
		}
		else if ((point[X] + 1) == lst->map->x && point[Y] == lst->map->y)
		{
			line->stop[X] = lst->pixel->x;
			line->stop[Y] = lst->pixel->y;
			line->color = lst->pixel->color;
		}
		lst = lst->next;
	}
}

void	ft_find_next_point_y(t_list *lst, t_line *line, int point[2])
{
	ft_init_line(line);
	while (lst)
	{
		if (point[X] == lst->map->x && point[Y] == lst->map->y)
		{
			line->start[X] = lst->pixel->x;
			line->start[Y] = lst->pixel->y;
			line->color = lst->pixel->color;
		}
		if (point[X] == lst->map->x && (point[Y] + 1) == lst->map->y)
		{
			line->stop[X] = lst->pixel->x;
			line->stop[Y] = lst->pixel->y;
			line->color = lst->pixel->color;
		}
		lst = lst->next;
	}
}
