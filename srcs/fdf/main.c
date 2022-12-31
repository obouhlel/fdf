/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:43:31 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/31 15:49:22 by obouhlel         ###   ########.fr       */
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
		return (0);
	}
	if (!ft_main_parsing(fd, vars))
	{
		ft_putendl_fd("Error", 1);
		ft_free_vars(vars);
		close(fd);
		return (0);
	}
	close(fd);
	ft_map_init_nb_line(vars->map);
	ft_map_print(vars->map);
	ft_color_print(vars->color);
	window_init(vars);
	ft_free_vars(vars);
	return (1);
}

int	main(int ac, char **av)
{
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
		ft_free_vars(vars);
		return (0);
	}
	if (!main_fdf(vars, av[1]))
		return (0);
	return (0);
}
