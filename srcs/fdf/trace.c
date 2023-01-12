/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:34:15 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 15:16:46 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// static void	ft_put_pixel_test(t_vars *vars, t_list *lst)
// {
// 	while (lst)
// 	{
// 		put_pixel(vars, lst->pixel->x, lst->pixel->y, lst->pixel->color);
// 		lst = lst->next;
// 	}
// }

int	ft_check_line(t_line line)
{
	if (line.start[X] == -1 || line.start[Y] == -1 || \
		line.stop[X] == -1 || line.stop[Y] == -1)
		return (0);
	return (1);
}

void	ft_trace_line(t_vars *vars, t_list *lst)
{
	t_line	line;
	int		point[2];
	int		x;
	int		y;

	y = 0;
	while (y <= vars->y_max)
	{
		point[Y] = y;
		x = 0;
		while (x <= vars->x_max)
		{
			point[X] = x;
			ft_find_next_point_x(lst, &line, point);
			if (ft_check_line(line))
				ft_put_line(vars, line);
			ft_find_next_point_y(lst, &line, point);
			if (ft_check_line(line))
				ft_put_line(vars, line);
			x++;
		}
		y++;
	}
}

void	ft_trace_img(t_vars *vars)
{
	ft_calcule_pixel(vars, vars->lst);
	ft_trace_line(vars, vars->lst);
}
