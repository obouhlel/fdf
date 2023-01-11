/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:08:58 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/11 18:25:14 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

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
	int		z;
	int		x;
	int		color;

	tmp = NULL;
	x = 0;
	while (*str)
	{
		color = 0;
		while (*str == ' ')
			str++;
		z = ft_atoi(str);
		str += ft_calcule_offset(z, 10);
		if (*str == ',')
		{
			color = ft_atoi_base_16(++str);
			str += ft_calcule_offset(color, 16) + 2;
		}
		tmp = ft_lst_new(ft_new_map(x++, y, z, color), NULL, NULL);
		if (!tmp || !tmp->map)
			return (NULL);
		ft_lst_add_back(lst, tmp);
	}
	return (lst);
}

static int	ft_find_x_max_map(t_list *lst)
{
	int	x_max;

	lst = ft_lst_last(lst);
	x_max = lst->map->x;
	return (x_max);
}

void	*ft_main_parsing(int fd, t_vars *vars)
{
	char	*str;
	int		y;

	str = NULL;
	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (!ft_check_parsing(str))
			return (free(str), NULL);
		if (!ft_create_map(&(vars->lst), str, y))
			return (free(str), NULL);
		if (y == 0)
			vars->x_max = ft_find_x_max_map(vars->lst);
		free(str);
		y++;
	}
	vars->y_max = y;
	return (SUCCESS);
}
