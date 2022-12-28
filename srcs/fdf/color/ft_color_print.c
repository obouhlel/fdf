/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:41:32 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 21:50:03 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_color_print(t_color *color)
{
	if (!color)
		ft_putendl_fd("(null)", 1);
	while (color)
	{
		ft_putstr_fd("colone = ", 1);
		ft_putnbr_fd(color->col, 1);
		ft_putstr_fd(", line = ", 1);
		ft_putnbr_fd(color->line, 1);
		ft_putchar_fd(' ', 1);
		ft_putendl_fd(color->hex, 1);
		color = color->next;
	}
}
