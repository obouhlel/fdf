/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:16:41 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 18:20:25 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_init_find(t_point *find)
{
	int		i;
	int		j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			find[i].a[j] = INT_MIN;
			j++;
		}
		i++;
	}
}

t_point	*ft_next_point(t_point point, t_projection *projection, t_point find[2])
{
	ft_init_find(find);
	while (projection)
	{
		if (projection->point[X] == (point.a[X] + 1) \
			&& projection->point[Y] == point.a[Y])
		{
			find[X].a[X] = projection->x;
			find[X].a[Y] = projection->y;
			find[X].color = projection->color;
		}
		if (projection->point[Y] == (point.a[Y] + 1) \
			&& projection->point[X] == point.a[X])
		{
			find[Y].a[X] = projection->x;
			find[Y].a[Y] = projection->y;
			find[Y].color = projection->color;
		}
		projection = projection->next;
	}
	return (find);
}
