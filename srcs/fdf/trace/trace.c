/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:21:01 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 13:44:25 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_put_point(t_projection *projection, t_vars *vars)
{
	const float	off_x = ((WIN_X - 1) / 3);
	const float	off_y = ((WIN_Y - 1) / 3);

	while (projection)
	{
		mlx_pixel_put(vars->mlx, vars->win, \
		(off_x + projection->x), (off_y + projection->y), \
		0xFFFFFF);
		projection = projection->next;
	}
}

void	*ft_check_find(t_point	find)
{
	if (find.a[X] == 0 && find.a[Y] == 0)
		return (FAIL);
	return (SUCCESS);
}

void	ft_trace_line(t_vars *vars, t_projection *projection)
{
	int		i;
	t_line	line;
	t_point	point;
	t_point	find[2];

	while (projection)
	{
		line.a[X] = projection->x;
		line.a[Y] = projection->y;
		point.a[X] = projection->point[X];
		point.a[Y] = projection->point[Y];
		ft_next_point(point, vars->projection, find);
		i = 0;
		while (i < 2)
		{
			if (ft_check_find(find[i]) == SUCCESS)
			{
				line.b[X] = find[i].a[X];
				line.b[Y] = find[i].a[Y];
				line.color = find[i].color;
				ft_put_line(vars, line);
			}
			i++;
		}
		projection = projection->next;
	}
}

void	ft_trace(t_vars *vars)
{
	ft_size_line(25, vars->projection);
	ft_trace_line(vars, vars->projection);
	// ft_put_point(vars->projection, vars);
}
