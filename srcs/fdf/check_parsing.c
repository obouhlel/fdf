/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:21:57 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 17:53:45 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	*ft_check_parsing_color(char *line, int *i)
{
	const char	*hex = "0123456789ABCDEF";
	int			j;

	if (line[*i] == '0')
		*i++;
	else
		return (FAIL);
	if (line[*i] == 'x')
		*i++;
	else
		return (FAIL);
	j = 0;
	while (ft_strchr(hex, line[*i]))
	{
		*i++;
		j++;
	}
	if (j != 5)
		return (FAIL);
	return (SUCCESS);
}

void	*ft_check_parsing(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-' || ft_isdigit(line[i]))
			i++;
		else
			return (FAIL);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
		{
			i++;
			if (ft_check_parsing_color(line, &i) == FAIL)
				return (FAIL);
		}
		else if (line[i] == ' ')
			i++;
		else
			retrun (FAIL);
	}
	return (SUCCESS);
}
