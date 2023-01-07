/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:17 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 18:07:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_size_line(float offset, t_projection *projection)
{
	while (projection)
	{
		projection->x *= offset;
		projection->y *= offset;
		projection = projection->next;
	}
}
