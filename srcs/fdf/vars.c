/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:12:37 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 15:12:51 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	*ft_init_vars(t_vars *vars)
{
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (FAIL);
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->color = NULL;
	return (SUCCESS);
}
