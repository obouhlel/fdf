/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:46 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/11 11:03:17 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static void	*ft_check_find(t_point	find)
{
	if (find.a[X] == INT_MIN && find.a[Y] == INT_MIN)
		return (FAIL);
	return (SUCCESS);
}

static void	ft_trace_line(t_vars *vars, t_projection *projection)
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

static void	ft_size_line(float offset, t_projection *projection)
{
	while (projection)
	{
		projection->x *= offset;
		projection->y *= offset;
		projection = projection->next;
	}
}

void	ft_trace(t_vars *vars)
{
	ft_size_line(vars->size, vars->projection);
	ft_trace_line(vars, vars->projection);
}
