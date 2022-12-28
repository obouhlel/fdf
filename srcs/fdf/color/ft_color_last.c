/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:19:15 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 15:05:02 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_color	*ft_color_last(t_color *color)
{
	if (!color)
		return (FAIL);
	while (color && color->next)
		color = color->next;
	return (color);
}
