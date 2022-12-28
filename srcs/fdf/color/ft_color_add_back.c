/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:17:56 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 14:18:02 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_color_add_back(t_color **color, t_color *new)
{
	t_color	*last;

	last = NULL;
	if (!color | !new)
		return ;
	if (!*color)
	{
		(*color) = new;
		return ;
	}
	last = ft_color_last(*color);
	if (!last)
		return ;
	last->next = new;
}
