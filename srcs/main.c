/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:11 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/25 20:06:22 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(void)
{
	exit(0);
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y, "FDF obouhlel");
	mlx_hook(data->win_ptr, 17, 0, &close_window, 0);
	mlx_loop(data->mlx_ptr);
	return (0);
}
