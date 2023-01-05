/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:17 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/05 14:00:19 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_size_line(double offset, t_matrice_2D *mat_2d)
{
	while (mat_2d)
	{
		mat_2d->x *= offset;
		mat_2d->y *= offset;
		mat_2d = mat_2d->next;
	}
}
