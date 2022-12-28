/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:21:57 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 21:07:50 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	*ft_check_parsing_color(char *line, int *i)
{
	const char	*hex = "0123456789ABCDEF";
	int			i_bis;
	int			j;

	i_bis = *i;
	if (line[i_bis] == '0')
		i_bis++;
	else
		return (FAIL);
	if (line[i_bis] == 'x')
		i_bis++;
	else
		return (FAIL);
	j = 0;
	while (ft_strchr(hex, line[i_bis]))
	{
		i_bis++;
		j++;
	}
	*i = i_bis;
	if (j != 6)
		return (FAIL);
	return (SUCCESS);
}

void	*ft_check_parsing(char *line)
{
	int			i;
	int			tmp;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			i++;
		tmp = i;
		while (ft_isdigit(line[i]))
			i++;
		if (tmp == i)
			return (FAIL);
		if (line[i] == ',')
		{
			i++;
			if (!ft_check_parsing_color(line, &i))
				return (FAIL);
		}
		if (line[i] == ' ')
			i++;
	}
	return (SUCCESS);
}
