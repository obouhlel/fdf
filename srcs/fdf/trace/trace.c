/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:21:01 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 13:49:56 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

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
		i = -1;
		while (++i < 2)
		{
			if (ft_check_find(find[i]) == SUCCESS)
			{
				line.b[X] = find[i].a[X];
				line.b[Y] = find[i].a[Y];
				line.color = find[i].color;
				ft_put_line(vars, line);
			}
		}
		projection = projection->next;
	}
}

void	ft_trace(t_vars *vars)
{
	ft_size_line(vars->size, vars->projection);
	ft_trace_line(vars, vars->projection);
}
