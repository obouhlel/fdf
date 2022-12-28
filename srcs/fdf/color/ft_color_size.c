/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:19:00 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 14:28:42 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

int	ft_color_size(t_color *color)
{
	int	size;

	size = 0;
	while (color)
	{
		size++;
		color = color->next;
	}
	return (size);
}
