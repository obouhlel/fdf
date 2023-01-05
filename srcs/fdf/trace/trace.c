/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:21:01 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/05 14:02:07 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_put_point(t_matrice_2D *mat_2d, t_vars *vars)
{
	const float	off_x = ((WIN_X - 1) / 3);
	const float	off_y = ((WIN_Y - 1) / 3);

	while (mat_2d)
	{
		mlx_pixel_put(vars->mlx, vars->win, \
		(off_x + mat_2d->x), (off_y + mat_2d->y), \
		0xFF);
		mat_2d = mat_2d->next;
	}
}

void	*ft_check_find(t_point	find)
{
	if (find.a[X] == 0 && find.a[Y] == 0)
		return (FAIL);
	return (SUCCESS);
}

void	ft_trace_line(t_vars *vars, t_matrice_2D *mat_2d)
{
	int		i;
	t_line	line;
	t_point	point;
	t_point	find[2];

	while (mat_2d)
	{
		line.a[X] = mat_2d->x;
		line.a[Y] = mat_2d->y;
		point.a[X] = mat_2d->point[X];
		point.a[Y] = mat_2d->point[Y];
		ft_next_point(point, vars->mat_2d, find);
		i = 0;
		while (i < 2)
		{
			if (ft_check_find(find[i]) == SUCCESS)
			{
				line.b[X] = find[i].a[X];
				line.b[Y] = find[i].a[Y];
				ft_put_line(vars, line);
			}
			i++;
		}
		mat_2d = mat_2d->next;
	}
}

void	ft_trace(t_vars *vars)
{
	ft_size_line(25, vars->mat_2d);
	ft_trace_line(vars, vars->mat_2d);
	// ft_put_point(vars->mat_2d, vars);
}
