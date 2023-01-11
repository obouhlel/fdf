/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:22:38 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 16:59:28 by obouhlel         ###   ########.fr       */
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
			y = 0.5 + line.a[Y] + (line.b[Y] - line.a[Y]) * \
			(x - line.a[X]) / (line.b[X] - line.a[X]);
			put_pixel(vars, vars->ofst[X] + x, vars->ofst[Y] + y, line.color);
			x++;
		}
	}
	else
	{
		while (y <= line.b[Y])
		{
			x = 0.5 + line.a[X] + (line.b[X] - line.a[X]) * \
			(y - line.a[Y]) / (line.b[Y] - line.a[Y]);
			put_pixel(vars, vars->ofst[X] + x, vars->ofst[Y] + y, line.color);
			y++;
		}
	}
}
