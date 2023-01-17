/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:09:58 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/17 18:12:23 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_calcule_pixel_point(t_vars *vars, t_list *lst)
{
	float	max_f[2];
	float	min_f[2];
	float	moy_f[2];
	int		moy_px[2];
	int		win[2];

	max_f[X] = ft_find_x_max_proj(lst);
	max_f[Y] = ft_find_y_max_proj(lst);
	min_f[X] = ft_find_x_min_proj(lst);
	min_f[Y] = ft_find_y_min_proj(lst);
	moy_f[X] = (max_f[X] - min_f[X]) / 2;
	moy_f[Y] = (max_f[Y] - min_f[Y]) / 2;
	win[X] = (WIN_X - 1 - 10);
	win[Y] = (WIN_Y - 1 - 10);
	moy_px[X] = win[X] / 2;
	moy_px[Y] = win[Y] / 2;
	vars->origin[X] = moy_f[X] * vars->dist_point - moy_px[X];
	vars->origin[Y] = moy_f[Y] * vars->dist_point - moy_px[Y];
}

static void	*ft_calcule_pixel_bis(t_vars *vars, t_list *lst)
{
	t_pixel	*pixel;
	int		x;
	int		y;
	int		color;

	ft_calcule_pixel_point(vars, lst);
	while (lst)
	{
		x = (lst->proj->x + 0.5) * vars->dist_point + vars->origin[X];
		y = (lst->proj->y + 0.5) * vars->dist_point + vars->origin[Y];
		if (lst->map->color == 0)
			color = 0xFFFFFF;
		else
			color = lst->map->color;
		pixel = ft_new_pixel(x, y, color);
		if (!pixel)
			return (NULL);
		lst->pixel = pixel;
		lst = lst->next;
	}
	return (SUCCESS);
}

void	*ft_calcule_pixel(t_vars *vars, t_list *lst)
{
	int	min[2];
	int	max[2];

	ft_calcule_pixel_bis(vars, lst);
	min[X] = ft_find_pixel_min_x(lst);
	min[Y] = ft_find_pixel_min_y(lst);
	while (lst)
	{
		lst->pixel->x += (min[X] * -1) + 5;
		lst->pixel->y += (min[Y] * -1) + 5;
		lst = lst->next;
	}
	max[X] = ft_find_pixel_max_x(vars->lst);
	max[Y] = ft_find_pixel_max_y(vars->lst);
	if (max[X] > WIN_X || max[Y] > WIN_Y)
	{
		vars->dist_point--;
		ft_lst_pixel_clear(vars->lst);
		ft_calcule_pixel(vars, vars->lst);
	}
	return (SUCCESS);
}
