/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:56:35 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/25 18:26:56 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static char	*error(char *tmp, char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

static char	*get_next_line_read(int fd, char *tmp)
{
	char	*buffer;
	ssize_t	rd;

	rd = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (rd && !ft_strchr_gnl(tmp, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (error(tmp, buffer));
		buffer[rd] = 0;
		tmp = ft_strjoin_gnl(tmp, buffer);
		if (tmp[0] == 0)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
	}
	free(buffer);
	return (tmp);
}

static char	*get_next_line_new_tmp(char *tmp, char *line)
{
	size_t	len_tmp;
	size_t	len_line;

	len_tmp = ft_strlen_gnl(ft_strchr_gnl(tmp, '\n'));
	len_line = ft_strlen_gnl(line);
	tmp = ft_substr_gnl(tmp, len_line, len_tmp);
	if (!tmp)
		return (error(tmp, NULL));
	return (tmp);
}

static void	get_next_line_new_buffer(char *buffer, char *tmp)
{
	size_t	len_tmp;
	size_t	i;

	len_tmp = ft_strlen_gnl(tmp);
	i = 0;
	while (i < len_tmp)
	{
		buffer[i] = tmp[i];
		i++;
	}
	free(tmp);
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;

	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	tmp = ft_strjoin_gnl(tmp, buffer);
	if (!tmp)
		return (error(tmp, NULL));
	tmp = get_next_line_read(fd, tmp);
	if (!tmp)
		return (error(tmp, NULL));
	line = ft_split_gnl(tmp);
	if (!line)
		return (error(tmp, NULL));
	tmp = get_next_line_new_tmp(tmp, line);
	if (!tmp)
		return (error(tmp, NULL));
	get_next_line_new_buffer(buffer, tmp);
	return (line);
}
