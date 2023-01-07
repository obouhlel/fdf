/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:38:53 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 11:38:58 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_projection_add_back(t_projection **projection, t_projection *new)
{
	t_projection	*last;

	last = NULL;
	if (!projection | !new)
		return ;
	if (!*projection)
	{
		(*projection) = new;
		return ;
	}
	last = ft_projection_last(*projection);
	if (!last)
		return ;
	last->next = new;
}
