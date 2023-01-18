/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:23:55 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 06:38:16 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	ft_base_is_16(char c)
{
	const char	*hex = "0123456789ABCDEFabcdef";
	int			i;

	i = 0;
	while (hex[i])
	{
		if (c == hex[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned int	ft_atoi_base_16(char *nstr)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = 0;
	if (nstr[i] == '0')
		i++;
	if (nstr[i] == 'x')
		i++;
	while (ft_base_is_16(nstr[i]))
	{
		if (nstr[i] >= '0' && nstr[i] <= '9')
			n = (n * 16) + nstr[i] - '0';
		if (nstr[i] >= 'A' && nstr[i] <= 'F')
			n = (n * 16) + nstr[i] - 'A' + 10;
		if (nstr[i] >= 'a' && nstr[i] <= 'f')
			n = (n * 16) + nstr[i] - 'a' + 10;
		i++;
	}
	return (n);
}
