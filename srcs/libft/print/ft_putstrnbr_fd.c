/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnbrendl_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:01:40 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/02 12:03:33 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putstrnbr_fd(char *s, int n, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putnbr_fd(n, fd);
	ft_putchar_fd('\n', fd);
}
