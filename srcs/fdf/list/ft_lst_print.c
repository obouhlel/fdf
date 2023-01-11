/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:27:29 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/11 17:25:17 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_lst_print(t_list *lst)
{
	while (lst)
	{
		if (lst->map)
		{
			ft_putendl_fd("\t\tMAP", 1);
			ft_putstrnbr_fd("x = ", lst->map->x, 1);
			ft_putstrnbr_fd("y = ", lst->map->y, 1);
			ft_putstrnbr_fd("z = ", lst->map->z, 1);
			ft_putstrnbr_fd("color = ", lst->map->color, 1);
		}
		if (lst->proj)
		{
			ft_putendl_fd("\t\tPROJECTION", 1);
			printf("x = %f\n", lst->proj->x);
			printf("y = %f\n", lst->proj->y);
		}
		if (lst->pixel)
		{
			ft_putendl_fd("\t\tPIXEL", 1);
			ft_putstrnbr_fd("x = ", lst->pixel->x, 1);
			ft_putstrnbr_fd("y = ", lst->pixel->y, 1);
			ft_putstrnbr_fd("color = ", lst->pixel->color, 1);
		}
		lst = lst->next;
	}
}
