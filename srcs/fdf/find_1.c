/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:52 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 12:51:33 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_better_dist(int x_max, int y_max)
{
	int			dist[2];
	const int	win_x_max = WIN_X - 1 - (5 * 2);
	const int	win_y_max = WIN_Y - 1 - (5 * 2);
	int			check[2];

	dist[X] = win_x_max / x_max;
	dist[Y] = win_y_max / y_max;
	check[X] = dist[Y] * x_max;
	check[Y] = dist[X] * y_max;
	if (check[X] < check[Y])
		return (dist[Y]);
	else
		return (dist[X]);
	return (EXIT_FAILURE);
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
