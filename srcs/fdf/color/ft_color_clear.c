/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:19:22 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 14:19:41 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_color_clear(t_color *color)
{
	t_color	*tmp;

	tmp = NULL;
	while (color)
	{
		tmp = color->next;
		free(color->hex);
		free(color);
		color = tmp;
	}
}