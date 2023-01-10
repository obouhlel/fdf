/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:11 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 13:54:08 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free_vars(vars);
	exit(0);
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
	if (keycode == PGUP)
	{
		vars->size++;
		ft_trace(vars);
	}
	return (EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
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
	vars->win = mlx_new_window(vars->mlx, WIN_X, WIN_Y, "FDF obouhlel");
	vars->img = mlx_new_image(vars->mlx, WIN_X, WIN_Y);
	vars->addr = mlx_get_data_addr(vars->img, &(vars->bit_per_pixel), \
									&(vars->size_line), &(vars->endian));
	ft_trace(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_key_hook(vars->win, &keyboard, vars);
	mlx_hook(vars->win, ON_KEYDOWN, KEYPRESSMASK, &keyboard, vars);
	mlx_hook(vars->win, ON_DESTROY, NOEVENTMASK, &close_window, vars);
	mlx_loop(vars->mlx);
	return (EXIT_SUCCESS);
}
