/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:43:31 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/26 20:05:14 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	main(int ac, char **av)
{
	int	fd;

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
	ft_main_parsing(fd);
	return (0);
}
