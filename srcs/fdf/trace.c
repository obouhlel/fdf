/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:34:15 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 13:36:33 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_put_pixel_test(t_vars *vars, t_list *lst)
{
	while (lst)
	{
		put_pixel(vars, lst->pixel->x, lst->pixel->y, lst->pixel->color);
		lst = lst->next;
	}
}

void	ft_trace_img(t_vars *vars)
{
	ft_calcule_pixel(vars, vars->lst);
	ft_put_pixel_test(vars, vars->lst);
}
