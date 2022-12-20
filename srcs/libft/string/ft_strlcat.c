/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:50:35 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/03 14:59:57 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//the strlcat need to give lenth ant cat two string, if the size are not correct
//we send the source lenth, if the size is more we can cat if it's not we send
//the lenth of the source and the size
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	len_d;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	len_d = ft_strlen(dst);
	if (size > len_d)
	{
		len += len_d;
		if (size > len)
			size = len + 1;
		i = 0;
		while (i < size - len_d - 1)
		{
			dst[i + len_d] = src[i];
			i++;
		}
		dst[i + len_d] = 0;
	}
	else
		len += size;
	return (len);
}
