/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_set_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:48:17 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 13:27:36 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_projection_set_color(t_projection *projection, t_color *color)
{
	if (!color && !projection)
		return ;
	while (projection && color)
	{
		if (projection->point[X] == color->col \
			&& projection->point[Y] == color->line)
		{
			projection->color = color->value;
			color = color->next;
		}
		projection = projection->next;
	}
}
