/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:50:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 06:02:28 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	*ft_calcule_line(t_vars *vars, t_list *lst)
{
	int	y;

	y = 0;
	while (y <= vars->max_y_map)
	{
		while (lst && lst->next && y == lst->map->y)
		{
			lst->line_right.start[X] = lst->pixel->x;
			lst->line_right.start[Y] = lst->pixel->y;
			lst->line_right.stop[X] = lst->next->pixel->x;
			lst->line_right.stop[Y] = lst->next->pixel->y;
			lst->line_right.color = lst->pixel->color;
			lst = lst->next;
		}
		y++;
	}
	return (SUCCESS);
}
