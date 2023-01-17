/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:08:57 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/17 10:35:56 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_line	*ft_find_next_point_x(t_list *lst, int point[2])
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(line));
	if (!line)
		return (NULL);
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
	return (line);
}

t_line	*ft_find_next_point_y(t_list *lst, int point[2])
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(line));
	if (!line)
		return (NULL);
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
	return (line);
}

void	ft_pixel_grid(t_vars *vars)
{
	t_list	*list;
	int		point[2];
	int		x;
	int		y;

	list = vars->lst;
	y = 0;
	while (y <= vars->max_y_map)
	{
		point[Y] = y;
		x = 0;
		while (x <= ft_find_x_max_map(vars->lst, y))
		{
			point[X] = x;
			list->line_right = ft_find_next_point_x(vars->lst, point);
			if (!list->line_right)
			{
				ft_free_vars(vars);
				ft_putendl_fd("Error", 1);
				exit(0);
			}
			list->line_down = ft_find_next_point_y(vars->lst, point);
			if (!list->line_down)
			{
				ft_free_vars(vars);
				ft_putendl_fd("Error", 1);
				exit(0);
			}
			list = list->next;
			x++;
		}
		y++;
	}
}
