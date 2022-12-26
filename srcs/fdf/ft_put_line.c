/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:15:04 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/26 16:07:03 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_put_line(t_line line, t_info info)
{
	int	color;
	int	x;
	int	y;

	color = mlx_get_color_value(info.mlx, 0xFF00000);
	x = line.x_1;
	while (x < line.x_2)
	{
		y = line.y_1 + (line.y_2 - line.y_1) * \
			(x - line.x_1) / (line.x_2 - line.x_1);
		mlx_pixel_put(info.mlx, info.win, x, y, color);
		x++;
	}
}
