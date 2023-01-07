/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 18:07:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	*ft_main_projection(t_vars *vars)
{
	float	**mp;
	float	x;
	float	y;

	x = 0;
	y = 0;
	mp = ft_matrice_projection();
	if (!mp)
		return (FAIL);
	vars->projection = ft_calcule_projection(vars->map, mp, x, y);
	if (!vars->projection)
		return (ft_mp_clear(mp), FAIL);
	ft_mp_clear(mp);
	ft_id_projection(vars->map, vars->projection);
	ft_projection_set_color(vars->projection, vars->color);
	return (SUCCESS);
}
