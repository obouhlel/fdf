/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:11 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 13:26:30 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
		close_window(vars);
	return (0);
}

int	window_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_X, WIN_Y, "FDF obouhlel");
	mlx_key_hook(vars->win, &key_press, vars);
	mlx_hook(vars->win, ON_KEYDOWN, KEYPRESSMASK, &key_press, vars);
	mlx_hook(vars->win, ON_DESTROY, NOEVENTMASK, &close_window, vars);
	mlx_loop(vars->mlx);
	return (0);
}
