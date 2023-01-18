/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:08:58 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/18 15:50:26 by obouhlel         ###   ########.fr       */
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

static t_map	*ft_create_map_bis(char *str, int *offset, int x, int y)
{
	t_map	*map;
	int		i;
	int		z;
	int		color;

	i = 0;
	color = 0;
	while (str[i] == ' ')
		i++;
	z = ft_atoi(&str[i]);
	i += ft_calcule_offset(z, BASE_10);
	if (str[i] == ',')
	{
		i++;
		color = ft_atoi_base_16(&str[i]);
		i += ft_calcule_offset(color, BASE_16) + 2;
	}
	*offset = i;
	map = ft_new_map(x, y, z, color);
	return (map);
}

static void	*ft_create_map(t_list **lst, char *str, int x, int y)
{
	static t_list	*start_line = NULL;
	int				offset;
	t_list			*top;
	t_list			*tmp;
	t_map			*map;

	tmp = NULL;
	offset = 0;
	top = start_line;
	while (*str && *str != '\n')
	{
		map = ft_create_map_bis(str, &offset, ++x, y);
		if (!map)
			return (NULL);
		str += offset;
		tmp = ft_lst_new(map, top);
		if (!tmp)
			return (NULL);
		ft_lst_add_back(lst, tmp);
		if (top)
			top = top->next;
		if (x == 0)
			start_line = tmp;
	}
	return (lst);
}

void	ft_vars_max_x(t_vars *vars, t_list *lst)
{
	int	x_max;
	int	y;

	x_max = 0;
	y = 0;
	while (lst && lst->map->y == y)
	{
		if (x_max < lst->map->x)
			x_max = lst->map->x;
		lst = lst->next;
	}
	vars->max_x_map = x_max;
}

void	*ft_main_parsing(int fd, t_vars *vars)
{
	char	*str;
	char	start;
	int		x;
	int		y;

	start = 'S';
	str = &start;
	y = 0;
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			x = -1;
			if (!ft_create_map(&(vars->lst), str, x, y))
				return (free(str), NULL);
			ft_putstr_fd(str, 1);
			free(str);
			y++;
		}
	}
	vars->max_y_map = y;
	if (vars->lst)
		ft_vars_max_x(vars, vars->lst);
	return (SUCCESS);
}
