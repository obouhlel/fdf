/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:22:38 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/11 12:03:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_put_line(t_vars *vars, t_line line)
{
	float		x;
	float		y;

	x = line.a[X];
	y = line.a[Y];
	if ((line.a[X] - line.a[Y]) < (line.b[X] - line.b[Y]))
	{
		while (x <= line.b[X])
		{
			y = 0.5 + line.a[Y] + (line.b[Y] - line.a[Y]) *	(x - line.a[X]) / (line.b[X] - line.a[X]);
			put_pixel(vars, vars->ofst[X] + x, vars->ofst[Y] + y, line.color);
			x++;
		}
	}
	else
	{
		while (y <= line.b[Y])
		{
			x = 0.5 + line.a[X] + (line.b[X] - line.a[X]) * (y - line.a[Y]) / (line.b[Y] - line.a[Y]);
			put_pixel(vars, vars->ofst[X] + x, vars->ofst[Y] + y, line.color);
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

// 	d[X] = (line.b[X] - line.a[X]);
// 	d[Y] = (line.b[Y] - line.a[X]);

// 	if (abs(d[X]) > abs(d[Y]))
// 	{
// 		if (line.a[X] > line.b[X])
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
// 		while (line.a[X] <= line.b[X])
// 		{
// 			if (line.a[X] >= 0 && line.a[X] < WIN_X && line.a[Y] >= 0 && line.a[Y] < WIN_Y)
// 				put_pixel(vars, vars->ofst[X] + line.a[X], vars->ofst[Y] + line.a[Y], line.color);
// 			if (e > 0)
// 				e += 2 * d[Y];
// 			else
// 			{
// 				e += 2 * (d[X] - d[Y]);
// 				line.a[Y] += y_inc;
// 			}
// 			line.a[X]++;
// 		}
// 	}
// 	else
// 	{
// 		if (line.a[Y] > line.b[Y])
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
// 		while (line.a[Y] <= line.b[Y])
// 		{
// 			if (line.a[X] >= 0 && line.a[X] < WIN_X && line.a[Y] >= 0 && line.a[Y] < WIN_Y)
// 				put_pixel(vars, vars->ofst[X] + line.a[X], vars->ofst[Y] + line.a[Y], line.color);
// 			if (e > 0)
// 				e += 2 * d[X];
// 			else
// 			{
// 				e += 2 * (d[X] - d[Y]);
// 				line.a[X] += x_inc;
// 			}
// 			line.a[Y]++;
// 		}	
// 	}
// }
