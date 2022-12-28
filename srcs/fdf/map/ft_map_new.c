/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:52:14 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 13:53:45 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_map	*ft_map_new(int *line)
{
	t_map	*new;

	new = NULL;
	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->line = line;
	new->next_line = NULL;
	return (new);
}
