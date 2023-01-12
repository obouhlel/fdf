/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:21:57 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 12:34:49 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	*ft_valide_char(char c)
{
	const char	*valide_char = "0123456789abcdefABCDEFx-, \n";
	int			i;

	i = 0;
	while (valide_char[i])
	{
		if (c == valide_char[i])
			return (SUCCESS);
		i++;
	}
	return (FAIL);
}

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
	while (ft_strchr(hex, line[i_bis]) && line[i_bis])
	{
		i_bis++;
		j++;
	}
	*i = i_bis;
	if (j > 8 && j <= 0)
		return (FAIL);
	return (SUCCESS);
}

static void	*ft_check_parsing_value(char *line)
{
	const int	len = ft_strlen(line);
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			i++;
		while (ft_isdigit(line[i]) && line[i])
			i++;
		if (line[i] == ',')
		{
			i++;
			if (!ft_check_parsing_color(line, &i))
				return (FAIL);
		}
		while (line[i] == ' ' && line[i])
			i++;
		if (i == (len - 1) && line[i] == '\n')
			break ;
	}
	return (SUCCESS);
}

void	*ft_check_parsing(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_valide_char(line[i]) == FAIL)
			return (FAIL);
		i++;
	}
	if (!ft_check_parsing_value(line))
		return (FAIL);
	return (SUCCESS);
}
