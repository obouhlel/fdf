/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:49:42 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/03 14:59:57 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//to joint two string
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = (char *)ft_calloc((len1 + len2 + 1), sizeof(char));
	if (!s)
		return (NULL);
	(void)ft_strlcat(s, s1, (len1 + 1));
	(void)ft_strlcat(s, s2, (len1 + len2 + 1));
	return (s);
}
