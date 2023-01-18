/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:50:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 09:14:15 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_calcule_line(t_vars *vars, t_list *lst)
{
	t_list	*last;
	int		y;

	last = NULL;
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
		if (lst)
			last = lst;
		y++;
	}
	y = 0;
	while (last && y <= vars->max_y_map)
	{
		while (last && last->top)
		{
			last->line_down.start[X] = last->pixel->x;
			last->line_down.start[Y] = last->pixel->y;
			last->line_down.stop[X] = last->top->pixel->x;
			last->line_down.stop[Y] = last->top->pixel->y;
			last->line_down.color = last->pixel->color;
			last = last->previous;
		}
		last = last->previous;
		y++;
	}
}
