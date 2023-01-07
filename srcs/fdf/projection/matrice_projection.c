/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:21:03 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/07 18:07:26 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_mp_clear(float **mp)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (mp[i])
			free(mp[i]);
		i++;
	}
	if (mp)
		free(mp);
}

float	**ft_matrice_projection(void)
{
	float	**mp;
	int		i;

	mp = NULL;
	mp = (float **)malloc(sizeof(float *) * 2);
	if (!mp)
		return (FAIL);
	i = 0;
	while (i < 2)
	{
		mp[i] = (float *)malloc(sizeof(float) * 3);
		if (!mp[i])
			return (ft_mp_clear(mp), FAIL);
		i++;
	}
	mp[0][0] = sqrt(2) / 2;
	mp[0][1] = -sqrt(2) / 2;
	mp[0][2] = 0;
	mp[1][0] = 1 / sqrt(6);
	mp[1][1] = 1 / sqrt(6);
	mp[1][2] = -sqrt(2) / sqrt(3);
	return (mp);
}
