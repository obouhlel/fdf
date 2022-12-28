/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:43:31 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 12:12:21 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_vars	*vars;

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
	ft_init_vars(vars);
	ft_main_parsing(fd, vars);
	return (0);
}
