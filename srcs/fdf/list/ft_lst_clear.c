/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:56 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/16 15:27:34 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_lst_clear(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = lst->next;
		if (lst->map)
			free(lst->map);
		if (lst->proj)
			free(lst->proj);
		if (lst->pixel)
			free(lst->pixel);
		free(lst);
		lst = tmp;
	}
}

void	ft_lst_pixel_clear(t_list *lst)
{
	while (lst)
	{
		free(lst->pixel);
		lst = lst->next;
	}
}
