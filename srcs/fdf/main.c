/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:43:31 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/10 10:50:58 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	main_fdf_2(t_vars *vars)
{
	ft_map_init_nb_line(vars->map);
	if (!ft_main_projection(vars))
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		return (EXIT_FAILURE);
	}
	// ft_map_print(vars->map);
	// ft_color_print(vars->color);
	window_init(vars);
	ft_free_vars(vars);
	return (EXIT_SUCCESS);
}

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
	if (!main_fdf_2(vars))
		return (EXIT_FAILURE);
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
	if (!main_fdf(vars, av[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
