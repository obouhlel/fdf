/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:58:36 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/03 14:59:57 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//if it's a set
static int	ft_is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_start(const char *s, const char *set)
{
	size_t	start;

	start = 0;
	while (ft_is_set(s[0], set))
	{
		start++;
		s++;
	}
	return (start);
}

static size_t	ft_stop(const char *s, const char *set, size_t len)
{
	size_t	stop;

	stop = 0;
	while (ft_is_set(s[len - 1], set))
	{
		stop++;
		len--;
	}
	return (stop);
}

//to remove set at the begining and at the end
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	len;
	size_t	start;
	size_t	stop;

	if (!s1 || !set)
		return (NULL);
	if (*set == 0)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = ft_start(s1, set);
	stop = ft_stop(s1, set, len);
	if (len - stop == 0)
		return (ft_calloc(1, 1));
	s = ft_substr(s1, start, (len - start - stop));
	return (s);
}
