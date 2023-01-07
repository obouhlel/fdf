/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_clear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:19:59 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 17:20:03 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_projection_clear(t_projection *projection)
{
	t_projection	*tmp;

	while (projection)
	{
		tmp = projection->next;
		free(projection);
		projection = tmp;
	}
	free(projection);
}
