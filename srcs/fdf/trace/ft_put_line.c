/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:22:38 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 15:31:19 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static void	ft_put_line_bis(t_vars *vars, t_line line, float y)
{
	const float	off_x = ((WIN_X - 1) / 2);
	const float	off_y = ((WIN_Y - 1) / 5);
	float		x;

	while (y <= line.b[Y])
	{
		x = line.a[X] + (line.b[X] - line.a[X]) * \
		(y - line.a[Y]) / (line.b[Y] - line.a[Y]);
		put_pixel(vars, off_x + x, off_y + y, line.color);
		y++;
	}
}

void	ft_put_line(t_vars *vars, t_line line)
{
	const float	off_x = ((WIN_X - 1) / 2);
	const float	off_y = ((WIN_Y - 1) / 5);
	float		x;
	float		y;

	x = line.a[X];
	y = line.a[Y];
	if ((line.a[X] - line.a[Y]) < (line.b[X] - line.b[Y]))
	{
		while (x <= line.b[X])
		{
			y = line.a[Y] + (line.b[Y] - line.a[Y]) * \
			(x - line.a[X]) / (line.b[X] - line.a[X]);
			put_pixel(vars, off_x + x, off_y + y, line.color);
			x++;
		}
	}
	else
		ft_put_line_bis(vars, line, y);
}
