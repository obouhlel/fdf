/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:11 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/26 16:08:14 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	close_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	exit(0);
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == ESCAPE)
		close_window(info);
	return (0);
}

int	window_init(t_info info)
{
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIN_X, WIN_Y, "FDF obouhlel");
	mlx_key_hook(info.win, &key_press, &info);
	mlx_hook(info.win, ON_KEYDOWN, KEYPRESSMASK, &key_press, &info);
	mlx_hook(info.win, ON_DESTROY, NOEVENTMASK, &close_window, &info);
	mlx_loop(info.mlx);
	return (0);
}
