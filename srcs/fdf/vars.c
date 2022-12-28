/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:12:37 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 22:14:30 by obouhlel         ###   ########.fr       */
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
	vars->map = NULL;
	vars->color = NULL;
	return (vars);
}

void	ft_free_vars(t_vars *vars)
{
	if (vars->map)
		ft_map_clear(vars->map);
	if (vars->color)
		ft_color_clear(vars->color);
	if (vars->mlx)
		free(vars->mlx);
	free(vars);
}
