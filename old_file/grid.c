/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:28:01 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/05 12:28:33 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
	plan 2D

	A --- C
	|     |
	|     |
	B --- D

	point A	(MIN, MIN)
	point B	(MIN, MAX)
	point C	(MAX, MIN)
	point D	(MAX, MAX)

	MAX = (WIN_Y - 1) - ((WIN_Y - 1) / N)
	MIN = ((WIN_Y - 1) / N)
*/

void	ft_init_plan(t_plan_2d *plan, t_vars *vars)
{
	plan->a[X] = ((WIN_X - 1) / vars->map->nb_col);
	plan->a[Y] = ((WIN_Y - 1) / vars->map->nb_line);
	plan->b[X] = ((WIN_X - 1) / vars->map->nb_col);
	plan->b[Y] = (WIN_Y - 1) - ((WIN_Y - 1) / vars->map->nb_line);
	plan->c[X] = (WIN_X - 1) - ((WIN_X - 1) / vars->map->nb_col);
	plan->c[Y] = ((WIN_Y - 1) / vars->map->nb_line);
	plan->d[X] = (WIN_X - 1) - ((WIN_X - 1) / vars->map->nb_col);
	plan->d[Y] = (WIN_Y - 1) - ((WIN_Y - 1) / vars->map->nb_line);
}

void	ft_calculate_line(t_line *line, t_plan_2d plan, int type)
{
	if (type == LINE)
	{
		line->a[X] = plan.a[X];
		line->a[Y] = plan.a[Y];
		line->b[X] = plan.d[X];
		line->b[Y] = plan.c[Y];
	}
	else if (type == COLUMN)
	{
		line->a[X] = plan.a[X];
		line->a[Y] = plan.a[Y];
		line->b[X] = plan.b[X];
		line->b[Y] = plan.d[Y];
	}
	return ;
}

void	ft_trace_grid_bis(t_vars *vars, t_plan_2d plan)
{
	int		i;
	t_line	line;

	ft_calculate_line(&line, plan, COLUMN);
	i = 0;
	while (i < vars->map->nb_col)
	{
		if (i == (vars->map->nb_col - 1))
		{
			line.a[X] = plan.d[X];
			line.b[X] = plan.d[X];
		}
		ft_put_line(vars, line);
		line.a[X] += plan.d[X] / vars->map->nb_col;
		line.b[X] += plan.d[X] / vars->map->nb_col;
		i++;
	}
}

void	ft_trace_grid(t_vars *vars)
{
	t_plan_2d	plan;
	t_line		line;
	int			i;

	ft_init_plan(&plan, vars);
	ft_calculate_line(&line, plan, LINE);
	i = 0;
	while (i < vars->map->nb_line)
	{
		if (i == (vars->map->nb_line - 1))
		{
			line.a[Y] = plan.d[Y];
			line.b[Y] = plan.d[Y];
		}
		ft_put_line(vars, line);
		line.a[Y] += plan.d[Y] / vars->map->nb_line;
		line.b[Y] += plan.d[Y] / vars->map->nb_line;
		i++;
	}
	ft_trace_grid_bis(vars, plan);
}