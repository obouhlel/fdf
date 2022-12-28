/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:43:31 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 21:53:03 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_vars	*vars;

	vars = NULL;
	vars = ft_init_vars(vars);
	if (!vars)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (ac != 2)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (!ft_main_parsing(fd, vars))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	ft_map_print(vars->map);
	ft_color_print(vars->color);
	ft_map_clear(vars->map);
	vars->map = NULL;
	ft_color_clear(vars->color);
	vars->color = NULL;
	free(vars);
	return (0);
}
