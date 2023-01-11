/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:00:02 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/11 11:00:04 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_projection	*ft_new_matrice_2d(float x, float y)
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
