/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:18:06 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 15:05:00 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_color_add_back(t_color **color, t_color *new)
{
	if (!color && !new)
		return ;
	if (!*color)
	{
		(*color) = new;
		return ;
	}
	new->next = (*color);
	(*color) = new;
}
