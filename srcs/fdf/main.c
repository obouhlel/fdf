/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:00:26 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 05:59:37 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	main_fdf_bis(t_vars *vars)
{
	if (!ft_main_projection(vars))
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		return (EXIT_FAILURE);
	}
	vars->dist_point = ft_calculate_dist_point(vars);
	ft_calcule_pixel(vars, vars->lst);
	ft_calcule_line(vars, vars->lst);
	window_init(vars);
	ft_free_vars(vars);
	return (EXIT_SUCCESS);
}

static int	main_fdf(int fd)
{
	t_vars	*vars;

	vars = NULL;
	vars = ft_init_vars(vars);
	if (!vars)
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	if (!ft_main_parsing(fd, vars) || !(vars->lst))
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	if (main_fdf_bis(vars))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	if (main_fdf(fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
