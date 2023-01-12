/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:09:58 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 13:32:01 by obouhlel         ###   ########.fr       */
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

static void	*ft_calcule_pixel(t_vars *vars, t_list *lst)
{
	t_pixel	*pixel;
	int		x;
	int		y;
	int		color;

	ft_calcule_pixel_point(vars, lst, vars->dist_point);
	while (lst)
	{
		x = (lst->proj->x) * vars->dist_point + vars->origin[X];
		y = (lst->proj->y) * vars->dist_point + vars->origin[Y];
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

static void	ft_put_pixel_test(t_vars *vars, t_list *lst, int min_x, int min_y)
{
	while (lst)
	{
		put_pixel(vars, lst->pixel->x + min_x, lst->pixel->y + min_y, lst->pixel->color);
		lst = lst->next;
	}
}

int	ft_pixel_min_x(t_list *lst)
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

int	ft_pixel_min_y(t_list *lst)
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

void	ft_trace_img(t_vars *vars)
{
	int	min_x;
	int	min_y;

	ft_calcule_pixel(vars, vars->lst);
	min_x = -1 * ft_pixel_min_x(vars->lst);
	min_y = -1 * ft_pixel_min_y(vars->lst);
	ft_put_pixel_test(vars, vars->lst, min_x, min_y);
}
