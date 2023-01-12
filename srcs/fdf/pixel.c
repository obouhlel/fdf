/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:09:58 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 11:55:02 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_calcule_pixel_point(t_vars *vars, t_list *lst, int dist_point)
{
	float	moy_f[2];
	int		moy_px[2];
	int		win[2];
	float	max_f[2];
	float	min_f[2];

	max_f[X] = ft_find_x_max_proj(lst);
	max_f[Y] = ft_find_y_max_proj(lst);
	min_f[X] = ft_find_x_min_proj(lst);
	min_f[Y] = ft_find_y_min_proj(lst);
	moy_f[X] = (max_f[X] - min_f[X]) / 2;
	moy_f[Y] = (max_f[Y] - min_f[Y]) / 2;
	win[X] = WIN_X - 1 - (5 * 2);
	win[Y] = WIN_Y - 1 - (5 * 2);
	moy_px[X] = win[X] / 2;
	moy_px[Y] = win[Y] / 2;
	vars->origin[X] = moy_f[X] * dist_point - moy_px[X];
	vars->origin[Y] = moy_f[Y] * dist_point - moy_px[Y];
}

void	ft_calcule_pixel(t_vars *vars, t_list *lst)
{
	ft_calcule_pixel_point(vars, lst, vars->dist_point);
	while (lst)
	{
		lst->pixel->x = lst->proj->x * vars->dist_point + vars->origin[X];
		lst->pixel->y = lst->proj->y * vars->dist_point + vars->origin[Y];
		if (lst->map->color == 0)
			lst->pixel->color = 0xFFFFFF;
		else
			lst->pixel->color = lst->map->color;
		lst = lst->next;
	}
}
