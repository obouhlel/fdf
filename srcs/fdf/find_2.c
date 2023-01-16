/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:52:41 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/16 15:47:24 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_find_x_max_map(t_list *lst, int y)
{
	int	x_max;

	x_max = 0;
	while (lst)
	{
		while (lst && lst->map->y == y)
		{
			if (x_max < lst->map->x)
				x_max = lst->map->x;
			lst = lst->next;
		}
		if (x_max > 0)
			return (x_max);
		lst = lst->next;
	}
	return (x_max);
}

int	ft_find_pixel_min_x(t_list *lst)
{
	int	min;

	min = lst->pixel->x;
	while (lst)
	{
		if (min > lst->pixel->x)
			min = lst->pixel->x;
		lst = lst->next;
	}
	return (min);
}

int	ft_find_pixel_min_y(t_list *lst)
{
	int	min;

	min = lst->pixel->y;
	while (lst)
	{
		if (min > lst->pixel->y)
			min = lst->pixel->y;
		lst = lst->next;
	}
	return (min);
}

int	ft_find_pixel_max_x(t_list *lst)
{
	int	max;

	max = lst->pixel->x;
	while (lst)
	{
		if (max < lst->pixel->x)
			max = lst->pixel->x;
		lst = lst->next;
	}
	return (max);
}

int	ft_find_pixel_max_y(t_list *lst)
{
	int	max;

	max = lst->pixel->y;
	while (lst)
	{
		if (max < lst->pixel->y)
			max = lst->pixel->y;
		lst = lst->next;
	}
	return (max);
}
