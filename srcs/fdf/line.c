/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:50:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 15:34:32 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_calcule_line_bis(t_list *lst)
{
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

void	ft_calcule_line(t_vars *vars, t_list *lst)
{
	t_list	*tmp;
	int		y;

	y = 0;
	tmp = NULL;
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
		if (y == 0)
			tmp = lst;
		lst = lst->next;
		y++;
	}
	if (tmp)
		tmp = tmp->next;
	ft_calcule_line_bis(tmp);
}
