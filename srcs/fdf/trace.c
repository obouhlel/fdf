/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:34:15 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/16 12:32:27 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
	while (y <= vars->max_y_map)
	{
		point[Y] = y;
		x = 0;
		while (x <= ft_find_x_max_map(lst, y))
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
