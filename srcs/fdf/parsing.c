/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:10:36 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/26 20:15:04 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	*ft_main_parsing(int fd)
{
	char	*str;
	char	**strs;
	char	**split_color;
	char	*color;
	char	*tmp;
	int		i;
	int		line;

	line = 0;
	color = NULL;
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		strs = ft_split(str, ' ');
		if (!strs)
			return (NULL);
		i = 0;
		while (strs[i])
		{
			if (ft_strchr(strs[i], ',') != NULL)
			{
				split_color = ft_split(strs[i], ',');
				if (!split_color)
					return (NULL);
				free(strs[i]);
				strs[i] = ft_strdup(split_color[0]);
				if (!strs[i])
					return (NULL);
				if (color)
				{
					color = ft_strjoin(color, "\n");
					if (!color)
						return (NULL);
				}
				color = ft_strjoin(color, "y = ");
				if (!color)
					return (NULL);
				tmp = ft_itoa(line);
				if (!tmp)
					return (NULL);
				color = ft_strjoin(color, tmp);
				if (!color)
					return (NULL);
				free(tmp);
				color = ft_strjoin(color, " ; x = ");
				if (!color)
					return (NULL);
				tmp = ft_itoa(i);
				if (!tmp)
					return (NULL);
				color = ft_strjoin(color, tmp);
				if (!color)
					return (NULL);
				free(tmp);
				color = ft_strjoin(color, " ; color = ");
				if (!color)
					return (NULL);
				color = ft_strjoin(color, split_color[1]);
				if (!color)
					return (NULL);
				free(split_color[0]);
				free(split_color[1]);
				free(split_color);
			}
			free(strs[i]);
			i++;
		}
		free(strs);
		free(str);
		line++;
	}
	ft_putendl_fd(color, 1);
	free (color);
	return (OK);
}
