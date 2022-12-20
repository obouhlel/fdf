/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:54:16 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/03 14:59:57 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//to count the number of the digit for n
static size_t	ft_strsize(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
	{
		size++;
		return (size);
	}
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

//the main function for the int to ascii
char	*ft_itoa(int n)
{
	char		*nstr;
	size_t		size;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	size = ft_strsize(n);
	nstr = (char *)malloc((size + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	nstr[size] = 0;
	if (n == 0)
		nstr[0] = '0';
	if (n < 0)
		nstr[0] = '-';
	while (n)
	{
		if (n > 0)
			nstr[size - 1] = (n % 10) + 48;
		else
			nstr[size - 1] = (-n % 10) + 48;
		n /= 10;
		size--;
	}
	return (nstr);
}
