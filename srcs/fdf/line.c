/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:50:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 14:39:34 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_calcule_line(t_vars *vars, t_list *lst)
{
	int		y;

	y = 0;
	while (lst && y <= vars->max_y_map)
	{
		while (lst && lst->next && lst->map->x < vars->max_x_map)
		{
			lst->line_right.start[X] = lst->pixel->x;
			lst->line_right.start[Y] = lst->pixel->y;
			lst->line_right.stop[X] = lst->next->pixel->x;
			lst->line_right.stop[Y] = lst->next->pixel->y;
			lst->line_right.color = lst->pixel->color;
			lst = lst->next;
		}
		lst = lst->next;
		y++;
	}
	lst = vars->lst;
	while (lst->map->y == 0)
		lst = lst->next;
	while (lst && lst->top && lst->map->y > 0)
	{
		lst->line_down.start[X] = lst->pixel->x;
		lst->line_down.start[Y] = lst->pixel->y;
		lst->line_down.stop[X] = lst->top->pixel->x;
		lst->line_down.stop[Y] = lst->top->pixel->y;
		lst->line_down.color = lst->pixel->color;
		lst = lst->next;
	}
}
