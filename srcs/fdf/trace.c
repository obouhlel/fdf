/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:34:15 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 07:01:51 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_trace_img(t_vars *vars)
{
	t_list	*list;

	list = vars->lst;
	while (list)
	{
		ft_put_line(vars, &(list->line_right));
		ft_put_line(vars, &(list->line_down));
		list = list->next;
	}
}
