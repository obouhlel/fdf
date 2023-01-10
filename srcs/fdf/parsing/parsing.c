/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:10:36 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 10:49:14 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static char	**ft_free_strs(char **strs)
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

static void	*ft_vars_color(t_color **color, char **strs, int line)
{
	int		i;
	char	**strs_color;
	t_color	*color_tmp;

	i = 0;
	while (strs[i])
	{
		if (ft_strchr(strs[i], ',') != NULL)
		{
			strs_color = ft_split(strs[i], ',');
			if (!strs_color)
				return (FAIL);
			free(strs[i]);
			strs[i] = strs_color[0];
			if (!strs[i])
				return (FAIL);
			color_tmp = ft_color_new(strs_color[1], (i + 1), line);
			if (!color_tmp)
				return (FAIL);
			ft_color_add_back(color, color_tmp);
			free(strs_color);
		}
		i++;
	}
	return (SUCCESS);
}

static void	*ft_vars_line(t_map **map, char **strs, int id_line)
{
	int		i;
	int		nb_col;
	int		*line;
	t_map	*map_tmp;

	nb_col = 0;
	while (strs[nb_col])
		nb_col++;
	line = (int *)malloc(sizeof(int) * nb_col);
	if (!line)
		return (FAIL);
	i = 0;
	while (strs[i])
	{
		line[i] = atoi(strs[i]);
		i++;
	}
	map_tmp = ft_map_new(line, nb_col, id_line);
	if (!map_tmp)
		return (FAIL);
	ft_map_add_back(map, map_tmp);
	return (SUCCESS);
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
		if (!ft_check_parsing(str))
			return (free(str), FAIL);
		strs = ft_split(str, ' ');
		if (!strs)
			return (free(str), FAIL);
		if (ft_strchr(str, ',') != NULL)
			if (!ft_vars_color(&(vars->color), strs, line))
				return (free(str), ft_free_strs(strs), FAIL);
		if (!ft_vars_line(&(vars->map), strs, line))
			return (free(str), ft_free_strs(strs), FAIL);
		strs = ft_free_strs(strs);
		free(str);
		line++;
	}
	return (SUCCESS);
}
