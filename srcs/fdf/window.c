/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:11 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/17 10:43:44 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free_vars(vars);
	exit(EXIT_SUCCESS);
}

int	keyboard(int keycode, t_vars *vars)
{
	static int	x = 0;
	static int	y = 0;

	if (keycode == ESCAPE)
		close_window(vars);
	if (keycode == RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, ++x, y);
	if (keycode == LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, --x, y);
	if (keycode == UP)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, --y);
	if (keycode == DOWN)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, ++y);
	return (EXIT_SUCCESS);
}

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*pixel;
	int		pos;

	pos = (y * vars->size_line + x * (vars->bit_per_pixel / 8));
	pixel = vars->addr + pos;
	*(unsigned int *)pixel = color;
}

int	window_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (EXIT_FAILURE);
	vars->win = mlx_new_window(vars->mlx, WIN_X, WIN_Y, "FDF obouhlel");
	if (!vars->win)
		return (EXIT_FAILURE);
	vars->img = mlx_new_image(vars->mlx, WIN_X, WIN_Y);
	if (!vars->img)
		return (EXIT_FAILURE);
	vars->addr = mlx_get_data_addr(vars->img, &(vars->bit_per_pixel), \
									&(vars->size_line), &(vars->endian));
	if (!vars->addr)
		return (EXIT_FAILURE);
	ft_trace_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_key_hook(vars->win, &keyboard, vars);
	mlx_hook(vars->win, ON_KEYDOWN, KEYPRESSMASK, &keyboard, vars);
	mlx_hook(vars->win, ON_DESTROY, NOEVENTMASK, &close_window, vars);
	mlx_loop(vars->mlx);
	return (EXIT_SUCCESS);
}
