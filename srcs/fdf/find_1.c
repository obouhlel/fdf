/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:52 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/16 15:11:50 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_better_dist(t_vars *vars)
{
	int	x_max;
	int	y_max;
	int	dist[2];
	int	check[2];

	x_max = ft_find_x_max_proj(vars->lst) + 1.5;
	y_max = ft_find_y_max_proj(vars->lst) + 1.5;
	if (y_max == 0)
		y_max = 1;
	if (x_max == 0)
		x_max = 1;
	dist[X] = (WIN_X - 1 - (5 * 2)) / x_max;
	dist[Y] = (WIN_Y - 1 - (5 * 2)) / y_max;
	check[X] = dist[X] * y_max;
	check[Y] = dist[Y] * x_max;
	if (check[Y] < (WIN_X - 1 - (5 * 2)))
		return (dist[Y]);
	if (check[X] < (WIN_Y - 1 - (5 * 2)))
		return (dist[X]);
	else
		return (2);
}

float	ft_find_x_min_proj(t_list *lst)
{
	float	min;

	min = lst->proj->x;
	while (lst)
	{
		if (min > lst->proj->x)
			min = lst->proj->x;
		lst = lst->next;
	}
	return (min);
}

float	ft_find_x_max_proj(t_list *lst)
{
	float	max;

	max = lst->proj->x;
	while (lst)
	{
		if (max < lst->proj->x)
			max = lst->proj->x;
		lst = lst->next;
	}
	return (max);
}

float	ft_find_y_min_proj(t_list *lst)
{
	float	min;

	min = lst->proj->y;
	while (lst)
	{
		if (min > lst->proj->y)
			min = lst->proj->y;
		lst = lst->next;
	}
	return (min);
}

float	ft_find_y_max_proj(t_list *lst)
{
	float	max;

	max = lst->proj->y;
	while (lst)
	{
		if (max > lst->proj->y)
			max = lst->proj->y;
		lst = lst->next;
	}
	return (max);
}
