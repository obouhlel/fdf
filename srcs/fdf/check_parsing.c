/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:21:57 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 05:39:28 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	*ft_valide_char(char c, int color)
{
	const char	*valide_char = " -0123456789\nabcdefABCDEFx,";
	int			i;

	i = 0;
	if (color == 0)
	{
		while (valide_char[i] && i <= 12)
		{
			if (c == valide_char[i])
				return (SUCCESS);
			i++;
		}
	}
	else
	{
		while (valide_char[i])
		{
			if (c == valide_char[i])
				return (SUCCESS);
			i++;
		}
	}
	return (FAIL);
}

static int	ft_check_parsing_color(char *line)
{
	const char	*hex = "0123456789abcdefABCDEF";
	int			i;

	i = 0;
	if (line[i] == '0')
		i++;
	else
		return (0);
	if (line[i] == 'x')
		i++;
	else
		return (0);
	while (line[i] && ft_strchr(hex, line[i]))
	{
		i++;
	}
	if (i > 8 && i <= 0)
		return (0);
	return (i);
}

static void	*ft_check_parsing_value_color(char *line)
{
	int	i;
	int	tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '-')
			i++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] == '-')
			return (FAIL);
		if (line[i] == ',')
		{
			tmp = ++i;
			i += ft_check_parsing_color(&line[i]);
			if (tmp == i)
				return (FAIL);
		}
		if (line[i] != ' ' && line[i] != '\n')
			return (FAIL);
	}
	return (SUCCESS);
}

static void	*ft_check_parsing_value(char *line)
{
	int			i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] == '-')
			i++;
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == '-')
			return (FAIL);
	}
	return (SUCCESS);
}

void	*ft_check_parsing(char *line)
{
	int	i;

	i = 0;
	if (ft_strchr(line, ','))
	{
		while (line[i])
		{
			if (ft_valide_char(line[i++], 1) == FAIL)
				return (FAIL);
		}
		if (!ft_check_parsing_value_color(line))
			return (FAIL);
	}
	else
	{
		while (line[i])
		{
			if (ft_valide_char(line[i++], 0) == FAIL)
				return (FAIL);
		}
		if (!ft_check_parsing_value(line))
			return (FAIL);
	}
	return (SUCCESS);
}
