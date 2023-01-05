/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:21:03 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/05 13:59:21 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

void	ft_mp_clear(double **mp)
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

double	**ft_matrice_projection(void)
{
	double	**mp;
	int		i;

	mp = NULL;
	mp = (double **)malloc(sizeof(double *) * 2);
	if (!mp)
		return (FAIL);
	i = 0;
	while (i < 2)
	{
		mp[i] = (double *)malloc(sizeof(double) * 3);
		if (!mp[i])
			return (ft_mp_clear(mp), FAIL);
		i++;
	}
	mp[0][0] = sqrt(2) / 2;
	mp[0][1] = -sqrt(2) / 2;
	mp[0][2] = 0;
	mp[1][0] = 1 / sqrt(6);
	mp[1][1] = 1 / sqrt(6);
	mp[1][2] = sqrt(2 / 3);
	return (mp);
}
