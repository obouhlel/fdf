/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:21:01 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/29 21:38:56 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_put_line(t_vars *vars, t_plan_2d start, t_plan_2d stop)
{
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	if ((start.x - start.y) < (stop.x - stop.y))
	{
		while (x <= stop.x)
		{
			y = start.y + (stop.y - start.y) * \
			(x - start.x) / (stop.x - start.x);
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
			x++;
		}
	}
	else
	{
		while (y <= stop.y)
		{
			x = start.x + (stop.x - start.x) * \
			(y - start.y) / (stop.y - start.y);
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
			y++;
		}
	}
}

int	ft_calcule_dist(t_plan_2d *start, t_plan_2d *stop, t_vars *vars, int type)
{
	int	offset;

	offset = 0;
	if (type == LINE)
	{
		start->x = 0;
		stop->x = 0;
		start->y = 0;
		stop->y = 0;
		offset = 0;
	}
	else if (type == COLONE)
	{
		start->y = 0;
		stop->y = 0;
		start->x = 0;
		stop->x = 0;
		offset = 0;
	}
	return (offset);
}

void	ft_trace_grid(t_vars *vars)
{
	// t_plan_2d	start;
	// t_plan_2d	stop;
	// int			offset;
	// int			i;

	// i = 0;
	// offset = ft_calcule_dist(&start, &stop, vars, LINE);
	// while (i < vars->nb_line)
	// {
	// 	ft_put_line(vars, start, stop);
	// 	start.y += offset;
	// 	stop.y += offset;
	// 	i++;
	// }
	// i = 0;
	// offset = ft_calcule_dist(&start, &stop, vars, COLONE);
	// while (i < vars->map->nb_col)
	// {
	// 	ft_put_line(vars, start, stop);
	// 	start.x += offset;
	// 	stop.x += offset;
	// 	i++;
	// }

	for (int row = 0; row < vars->nb_line; row++) {
  		for (int col = 0; col < vars->map->nb_col; col++) {
		int x1 = col * WIN_X;
		int y1 = row * WIN_Y;
		int x2 = x1 + WIN_X;
		int y2 = y1 + WIN_Y;
		mlx_pixel_put(vars->mlx, vars->win, x1, y1, 0xFFFFFF);
		mlx_pixel_put(vars->mlx, vars->win, x2, y2, 0xFFFFFF);
		mlx_line_put(vars->mlx, vars->win, x1, y1, x2, y1, 0xFFFFFF);
		mlx_line_put(vars->mlx, vars->win, x1, y2, x2, y2, 0xFFFFFF);
		mlx_line_put(vars->mlx, vars->win, x1, y1, x1, y2, 0xFFFFFF);
		mlx_line_put(vars->mlx, vars->win, x2, y1, x2, y2, 0xFFFFFF);
  }
}
}
