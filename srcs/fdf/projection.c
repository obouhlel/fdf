/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:06 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/15 01:00:58 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	*ft_calcule_proj(t_list *lst, float mp[2][3])
{
	t_proj	*proj;
	float	x;
	float	y;

	while (lst)
	{
		x = (mp[0][0] * lst->map->x) + (mp[0][1] * lst->map->y) + \
			(mp[0][2] * lst->map->z);
		y = (mp[1][0] * lst->map->x) + (mp[1][1] * lst->map->y) + \
			(mp[1][2] * lst->map->z);
		proj = ft_new_proj(x, y);
		if (!proj)
			return (NULL);
		lst->proj = proj;
		lst = lst->next;
	}
	return (SUCCESS);
}

// static void	ft_offset_proj(t_list *lst, float min[2])
// {
// 	while (lst)
// 	{
// 		lst->proj->x += min[X] * -1;
// 		lst->proj->y += min[Y] * -1;
// 		lst = lst->next;
// 	}
// }

void	*ft_main_projection(t_vars *vars)
{
	float	mp[2][3];
	// float	min[2];

	mp[0][0] = sqrt(2) / 2;
	mp[0][1] = -sqrt(2) / 2;
	mp[0][2] = 0;
	mp[1][0] = 1 / sqrt(6);
	mp[1][1] = 1 / sqrt(6);
	mp[1][2] = -sqrt(2) / sqrt(3);
	if (!ft_calcule_proj(vars->lst, mp))
		return (FAIL);
	// min[X] = ft_find_x_min_proj(vars->lst);
	// min[Y] = ft_find_y_min_proj(vars->lst);
	// ft_offset_proj(vars->lst, min);
	return (SUCCESS);
}
