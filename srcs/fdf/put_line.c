/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:22:38 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/16 11:55:52 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_swap_line(t_line *line, int d[2])
{
	float	tmp;

	tmp = line->start[X];
	line->start[X] = line->stop[X];
	line->stop[X] = tmp;
	tmp = line->start[Y];
	line->start[Y] = line->stop[Y];
	line->stop[Y] = tmp;
	d[X] = -d[X];
	d[Y] = -d[Y];
}

static void	ft_put_pixel_x(t_vars *vars, t_line line, int d[2], int y_inc)
{
	const int	e_inc_1 = 2 * d[Y];
	const int	e_inc_2 = 2 * (d[Y] - d[X]);
	int			e;
	int			x;
	int			y;

	e = 2 * d[Y] - d[X];
	x = line.start[X];
	y = line.start[Y];
	while (x <= line.stop[X])
	{
		if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
			put_pixel(vars, x, y, line.color);
		if (e < 0)
			e += e_inc_1;
		else
		{
			e += e_inc_2;
			y += y_inc;
		}
		x++;
	}
}

static void	ft_put_pixel_y(t_vars *vars, t_line line, int d[2], int x_inc)
{
	const int	e_inc_1 = 2 * d[X];
	const int	e_inc_2 = 2 * (d[X] - d[Y]);
	int			y;
	int			x;
	int			e;

	y = line.start[Y];
	x = line.start[X];
	e = 2 * d[X] - d[Y];
	while (y <= line.stop[Y])
	{
		if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
			put_pixel(vars, x, y, line.color);

		if (e < 0)
			e += e_inc_1;
		else
		{
			e += e_inc_2;
			x += x_inc;
		}
		y++;
	}
}

static void	ft_inc(int *inc, int *d)
{
	if (*d < 0)
	{
		*inc = -1;
			*d *= -1;
	}
}

void	ft_put_line(t_vars *vars, t_line line)
{
	int	d[2];
	int	y_inc;
	int	x_inc;

	d[X] = line.stop[X] - line.start[X];
	d[Y] = line.stop[Y] - line.start[Y];
	y_inc = 1;
	x_inc = 1;
	if (abs(d[X]) > abs(d[Y]))
	{
		if (line.start[X] > line.stop[X])
			ft_swap_line(&line, d);
		ft_inc(&y_inc, &d[Y]);
		ft_put_pixel_x(vars, line, d, y_inc);
	}
	else
	{
		if (line.start[Y] > line.stop[Y])
			ft_swap_line(&line, d);
		ft_inc(&x_inc, &d[X]);
		ft_put_pixel_y(vars, line, d, x_inc);
	}
}
