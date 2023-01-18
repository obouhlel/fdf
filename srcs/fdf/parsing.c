/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:08:58 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 05:23:36 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	ft_calcule_offset(int n, int base)
{
	int	size;

	size = 0;
	if (n == 0)
		return (++size);
	if (n < 0)
		size++;
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

static void	*ft_create_map(t_list **lst, char *str, int y)
{
	t_list	*tmp;
	int		x;
	int		z;
	int		color;

	x = 0;
	tmp = NULL;
	while (*str && *str != '\n')
	{
		color = 0;
		while (*str == ' ')
			str++;
		z = ft_atoi(str);
		str += ft_calcule_offset(z, BASE_10);
		if (*str == ',')
		{
			color = ft_atoi_base_16(++str);
			str += ft_calcule_offset(color, BASE_16) + 2;
		}
		tmp = ft_lst_new(ft_new_map(x++, y, z, color));
		if (!tmp || !tmp->map)
			return (NULL);
		ft_lst_add_back(lst, tmp);
	}
	return (lst);
}

void	*ft_main_parsing(int fd, t_vars *vars)
{
	char	*str;
	char	start;
	int		y;

	start = 'S';
	str = &start;
	y = 0;
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			if (!ft_check_parsing(str))
				return (free(str), NULL);
			if (!ft_create_map(&(vars->lst), str, y))
				return (free(str), NULL);
			ft_putstr_fd(str, 1);
			free(str);
			y++;
		}
	}
	vars->max_y_map = y;
	return (SUCCESS);
}
