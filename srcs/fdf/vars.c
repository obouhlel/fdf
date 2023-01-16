/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:12:37 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/16 12:37:38 by obouhlel         ###   ########.fr       */
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
	vars->bit_per_pixel = 0;
	vars->size_line = 0;
	vars->endian = 0;
	vars->lst = NULL;
	vars->origin[X] = 0;
	vars->origin[Y] = 0;
	vars->max_x_map = 0;
	vars->max_y_map = 0;
	vars->dist_point = 20;
	return (vars);
}

void	ft_free_vars(t_vars *vars)
{
	if (vars->lst)
		ft_lst_clear(vars->lst);
	if (vars->mlx)
		free(vars->mlx);
	free(vars);
}
