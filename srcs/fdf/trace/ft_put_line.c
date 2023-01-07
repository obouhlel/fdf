/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:22:38 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 11:28:21 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_put_line(t_vars *vars, t_line line)
{
	const double	off_x = ((WIN_X - 1) / 2);
	const double	off_y = ((WIN_Y - 1) / 5);
	double			x;
	double			y;

	x = line.a[X];
	y = line.a[Y];
	if ((line.a[X] - line.a[Y]) < (line.b[X] - line.b[Y]))
	{
		while (x <= line.b[X])
		{
			y = line.a[Y] + (line.b[Y] - line.a[Y]) * \
			(x - line.a[X]) / (line.b[X] - line.a[X]);
			mlx_pixel_put(vars->mlx, vars->win, off_x + x, off_y + y, line.color);
			x++;
		}
	}
	else
	{
		while (y <= line.b[Y])
		{
			x = line.a[X] + (line.b[X] - line.a[X]) * \
			(y - line.a[Y]) / (line.b[Y] - line.a[Y]);
			mlx_pixel_put(vars->mlx, vars->win, off_x + x, off_y + y, line.color);
			y++;
		}
	}
}
