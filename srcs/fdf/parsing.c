/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:10:36 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 14:34:38 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	*ft_vars_color(t_color **color, char **strs, int line)
{
	int		i;
	char	*strs_color;
	t_color	*color_tmp;

	i = 0;
	while (strs[i])
	{
		if (ft_strchr(strs[i], ',') != NULL)
		{
			strs_color = ft_split(strs[i], ',');
			if (!strs_color)
				return (NULL);
			free(strs[i]);
			strs[i] = ft_strdup(strs_color[0]);
			if (!strs[i])
				return (NULL);
			color_tmp = ft_color_new(strs_color[1], (i + 1), line);
			if (!color_tmp)
				return (NULL);
			ft_color_add_back(color, color_tmp);
		}
		i++;
	}
	return (OK);
}

void	*ft_line_value(t_map **map, char **strs)
{
	int		i;
	int		col_max;
	int		*line;
	t_map	*map_tmp;

	col_max = 0;
	while (strs[col_max])
		col_max++;
	line = (int *)malloc(sizeof(int) * col_max);
	if (!line)
		return (NULL);
	while (strs[i])
	{
		line[i] = atoi(strs[i]);
		i++;
	}
	map_tmp = ft_map_new(line);
	if (!map_tmp)
		return (NULL);
	ft_map_add_back(map, map_tmp);
	return (OK);
}

char	**ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

void	*ft_main_parsing(int fd, t_vars *vars)
{
	int		line;
	char	*str;
	char	**strs;

	line = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		strs = ft_split(str, ' ');
		if (!strs)
			return (NULL);
		if (ft_strchr(str, ',') != NULL)
			if (!ft_vars_color(&(vars->color), strs, line))
				return (NULL);
		if (!ft_line_value(&(vars->map), strs))
			return (NULL);
		strs = ft_free_strs(strs);
		line++;
	}
	return (OK);
}
