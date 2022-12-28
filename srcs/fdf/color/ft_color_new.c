/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:19:08 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 15:03:34 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

t_color	*ft_color_new(char *hex, int col, int line)
{
	t_color	*new;

	new = NULL;
	new = (t_color *)malloc(sizeof(t_color));
	if (!new)
		return (FAIL);
	new->col = col;
	new->line = line;
	new->hex = hex;
	new->next = NULL;
	return (new);
}
