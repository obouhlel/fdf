/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:56:41 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/25 18:26:56 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr_gnl(char *s, int nl)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen_gnl(s);
	i = 0;
	while (i < len)
	{
		if (s[i] == (unsigned char)nl)
			return ((char *)s + i + 1);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *tmp, char *buffer)
{
	char	*new_tmp;
	size_t	len_tmp;
	size_t	i;

	len_tmp = ft_strlen_gnl(tmp);
	new_tmp = (char *)malloc(sizeof(char) * (len_tmp + BUFFER_SIZE + 1));
	if (!new_tmp)
		return (NULL);
	new_tmp[0] = 0;
	i = 0;
	while (i < len_tmp)
	{
		new_tmp[i] = tmp[i];
		i++;
	}
	while (i < (len_tmp + BUFFER_SIZE))
	{
		new_tmp[i] = buffer[i - len_tmp];
		i++;
	}
	new_tmp[i] = 0;
	free(tmp);
	return (new_tmp);
}

char	*ft_split_gnl(char *tmp)
{
	size_t	len_line;
	size_t	end_line;
	size_t	i;
	char	*line;

	line = NULL;
	len_line = 0;
	end_line = 0;
	while (tmp[len_line] && tmp[len_line] != '\n')
		len_line++;
	if (tmp[len_line] == '\n')
		end_line++;
	line = (char *)malloc(sizeof(char) * (len_line + end_line + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (end_line)
		line[i] = '\n';
	line[i + end_line] = 0;
	return (line);
}

char	*ft_substr_gnl(char *tmp, size_t start, size_t len)
{
	char	*new_tmp;
	size_t	i;
	size_t	len_check;

	len_check = ft_strlen_gnl(tmp);
	if ((len + start) > len_check)
		len = len_check - start;
	if (start > len_check)
		len = 0;
	new_tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_tmp)
		return (0);
	i = 0;
	while (i < len)
	{
		new_tmp[i] = tmp[start + i];
		i++;
	}
	new_tmp[i] = 0;
	free(tmp);
	return (new_tmp);
}
