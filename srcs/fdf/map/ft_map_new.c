/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:52:14 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/31 14:58:04 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_map	*ft_map_new(int *line, int nb_col, int id_line)
{
	t_map	*new;

	new = NULL;
	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (FAIL);
	new->nb_col = nb_col;
	new->nb_line = -1;
	new->id_line = id_line;
	new->line = line;
	new->next_line = NULL;
	new->previous_line = NULL;
	return (new);
}
