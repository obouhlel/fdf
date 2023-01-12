/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:00:26 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 14:10:47 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	main_fdf(t_vars *vars, char *name_file)
{
	int	fd;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		return (EXIT_FAILURE);
	}
	if (!ft_main_parsing(fd, vars))
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	if (!ft_main_projection(vars))
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		return (EXIT_FAILURE);
	}
	ft_better_dist(vars, vars->x_max, vars->y_max);
	window_init(vars);
	ft_free_vars(vars);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars = NULL;
	vars = ft_init_vars(vars);
	if (!vars)
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	if (ac != 2)
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		return (EXIT_FAILURE);
	}
	if (main_fdf(vars, av[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
