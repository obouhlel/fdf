/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:32:39 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 08:17:39 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = NULL;
	if (!lst && new)
		return ;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	last = ft_lst_last(*lst);
	last->next = new;
	new->previous = last;
}
