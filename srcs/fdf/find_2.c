/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:52:41 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 14:54:30 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_find_pixel_min_x(t_list *lst)
{
	int	min;

	min = lst->pixel->x;
	while (lst)
	{
		if (min > lst->pixel->x)
			min = lst->pixel->x;
		lst = lst->next;
	}
	return (min);
}

int	ft_find_pixel_min_y(t_list *lst)
{
	int	min;

	min = lst->pixel->y;
	while (lst)
	{
		if (min > lst->pixel->y)
			min = lst->pixel->y;
		lst = lst->next;
	}
	return (min);
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
