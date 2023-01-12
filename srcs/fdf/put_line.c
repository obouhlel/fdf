/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:22:38 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 14:49:08 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_put_line(t_vars *vars, t_line line)
{
	int		x;
	int		y;

	x = line.start[X];
	y = line.start[Y];
	if ((line.start[X] - line.start[Y]) < (line.stop[X] - line.stop[Y]))
	{
		while (x <= line.stop[X])
		{
			y = line.start[Y] + (line.stop[Y] - line.start[Y]) \
				* (x - line.start[X]) / (line.stop[X] - line.start[X]);
			put_pixel(vars, x, y, line.color);
			x++;
		}
	}
	else
	{
		while (y <= line.stop[Y])
		{
			x = line.start[X] + (line.stop[X] - line.start[X]) \
				* (y - line.start[Y]) / (line.stop[Y] - line.start[Y]);
			put_pixel(vars, x, y, line.color);
			y++;
		}
	}
}

// static void	ft_swap_line(t_line *line)
// {
// 	float	tmp;

// 	tmp = line->a[X];
// 	line->a[X] = line->b[X];
// 	line->b[X] = tmp;
// 	tmp = line->a[Y];
// 	line->a[Y] = line->b[Y];
// 	line->b[Y] = tmp;
// }

// void	ft_put_line(t_vars *vars, t_line line)
// {
// 	int	d[2];
// 	int	e;
// 	int	x_inc;
// 	int	y_inc;

// 	d[X] = (line.stop[X] - line.start[X]);
// 	d[Y] = (line.stop[Y] - line.start[X]);

// 	if (abs(d[X]) > abs(d[Y]))
// 	{
// 		if (line.start[X] > line.stop[X])
// 		{
// 			ft_swap_line(&line);
// 			d[X] *= -1;
// 			d[Y] *= -1;
// 		}
// 		y_inc = 1;
// 		if (d[Y] < 0)
// 		{
// 			y_inc = -1;
// 			d[Y] *= -1;
// 		}
// 		e = 2 * d[Y] - d[X];
// 		while (line.start[X] <= line.stop[X])
// 		{
// 			if (line.start[X] >= 0 && line.start[X] < WIN_X && line.start[Y] >= 0 && line.start[Y] < WIN_Y)
// 				put_pixel(vars, vars->ofst[X] + line.start[X], vars->ofst[Y] + line.start[Y], line.color);
// 			if (e > 0)
// 				e += 2 * d[Y];
// 			else
// 			{
// 				e += 2 * (d[X] - d[Y]);
// 				line.start[Y] += y_inc;
// 			}
// 			line.start[X]++;
// 		}
// 	}
// 	else
// 	{
// 		if (line.start[Y] > line.stop[Y])
// 		{
// 			ft_swap_line(&line);
// 			d[X] *= -1;
// 			d[Y] *= -1;
// 		}
// 		x_inc = 1;
// 		if (d[X] < 0)
// 		{
// 			x_inc = -1;
// 			d[X] *= -1;
// 		}
// 		e = 2 * d[X] - d[Y];
// 		while (line.start[Y] <= line.stop[Y])
// 		{
// 			if (line.start[X] >= 0 && line.start[X] < WIN_X && line.start[Y] >= 0 && line.start[Y] < WIN_Y)
// 				put_pixel(vars, vars->ofst[X] + line.start[X], vars->ofst[Y] + line.start[Y], line.color);
// 			if (e > 0)
// 				e += 2 * d[X];
// 			else
// 			{
// 				e += 2 * (d[X] - d[Y]);
// 				line.start[X] += x_inc;
// 			}
// 			line.start[Y]++;
// 		}	
// 	}
// }
