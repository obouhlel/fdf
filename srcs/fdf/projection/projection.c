/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/05 12:23:31 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	*ft_main_projection(t_vars *vars)
{
	double	**mp;
	double	x;
	double	y;

	x = 0;
	y = 0;
	mp = ft_matrice_projection();
	if (!mp)
		return (FAIL);
	vars->mat_2d = ft_calcule_projection(vars->map, mp, x, y);
	if (!vars->mat_2d)
		return (ft_mp_clear(mp), FAIL);
	ft_mp_clear(mp);
	ft_id_mat_2d(vars->map, vars->mat_2d);
	return (SUCCESS);
}
