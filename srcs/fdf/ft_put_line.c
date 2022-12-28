/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:15:04 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 17:57:25 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_put_line(t_line line, t_vars *vars)
{
	int	color;
	int	x;
	int	y;

	color = mlx_get_color_value(vars->mlx, 0xFF00000);
	x = line.x_1;
	while (x < line.x_2)
	{
		y = line.y_1 + (line.y_2 - line.y_1) * \
			(x - line.x_1) / (line.x_2 - line.x_1);
		mlx_pixel_put(vars->mlx, vars->win, x, y, color);
		x++;
	}
}
