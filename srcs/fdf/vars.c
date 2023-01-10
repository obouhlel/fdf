/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:12:37 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 10:51:02 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_vars	*ft_init_vars(t_vars *vars)
{
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (FAIL);
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
	vars->addr = NULL;
	vars->bit_per_pixel = 8;
	vars->size_line = 20;
	vars->endian = 100;
	vars->map = NULL;
	vars->color = NULL;
	vars->projection = NULL;
	return (vars);
}

void	ft_free_vars(t_vars *vars)
{
	if (vars->map)
		ft_map_clear(vars->map);
	if (vars->color)
		ft_color_clear(vars->color);
	if (vars->projection)
		ft_projection_clear(vars->projection);
	if (vars->mlx)
		free(vars->mlx);
	free(vars);
}
