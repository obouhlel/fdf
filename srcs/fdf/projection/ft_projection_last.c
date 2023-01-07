/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:28:04 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 17:28:05 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_projection	*ft_projection_last(t_projection *projection)
{
	while (projection && projection->next)
		projection = projection->next;
	return (projection);
}
