/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:58 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/28 15:38:50 by obouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//Include libft, gnl, minilibx
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

//open, read, close, write, malloc, free, perror, strerror, exit, math lib
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

# define SUCCESS	(void *)1
# define FAIL		(void *)0

//window size
# define WIN_X 500
# define WIN_Y 500

//event define
enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define NOEVENTMASK	0b0
# define KEYPRESSMASK	0b1
# define KEYRELEASEMASK	0b10

//key
# define ESCAPE	65307

//color
typedef struct s_color
{
	int				col;
	int				line;
	char			*hex;
	struct s_color	*next;
}	t_color;

void	ft_color_add_back(t_color **color, t_color *new);
void	ft_color_add_back(t_color **color, t_color *new);
void	ft_color_clear(t_color *color);
t_color	*ft_color_last(t_color *color);
t_color	*ft_color_new(char *hex, int col, int line);
int		ft_color_size(t_color *color);

//map
typedef struct s_map
{
	int				col_max;
	int				id_line;
	int				*line;
	struct s_map	*previous_line;
	struct s_map	*next_line;
}	t_map;

void	ft_map_add_back(t_map **map, t_map *new);
void	ft_map_add_back(t_map **map, t_map *new);
void	ft_map_clear(t_map *map);
t_map	*ft_map_last(t_map *map);
t_map	*ft_map_new(int *line, int col_max, int id_line);
int		ft_map_size(t_map *map);

//structure mlx
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_color		*color;
}	t_vars;

typedef struct s_line
{
	int	x_1;
	int	x_2;
	int	y_1;
	int	y_2;
}	t_line;

//vars
void	*ft_init_vars(t_vars *vars);

//parsing
void	*ft_main_parsing(int fd, t_vars *vars);

//trace a line
void	ft_put_line(t_line line, t_vars vars);

//window
int		window_init(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		close_window(t_vars *vars);

#endif