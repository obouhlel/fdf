/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:37:24 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 16:47:54 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_projection	*ft_new_matrice_2d(double x, double y)
{
	t_projection	*projection;

	projection = NULL;
	projection = (t_projection *)malloc(sizeof(t_projection));
	if (!projection)
		return (FAIL);
	projection->point[X] = 0;
	projection->point[Y] = 0;
	projection->color = 0xFFFFFF;
	projection->x = x;
	projection->y = y;
	projection->next = NULL;
	return (projection);
}
