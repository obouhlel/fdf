/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:58 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/29 21:24:25 by obouhlel         ###   ########.fr       */
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
# define WIN_X 1200
# define WIN_Y 700

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

//map
typedef struct s_map
{
	int				nb_col;
	int				id_line;
	int				*line;
	struct s_map	*previous_line;
	struct s_map	*next_line;
}	t_map;

void	ft_map_add_back(t_map **map, t_map *new);
void	ft_map_add_back(t_map **map, t_map *new);
void	ft_map_clear(t_map *map);
t_map	*ft_map_last(t_map *map);
t_map	*ft_map_new(int *line, int nb_col, int id_line);
int		ft_map_size(t_map *map);
void	ft_map_print(t_map *map);

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
void	ft_color_print(t_color *color);

//structure mlx
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	int			nb_line;
	t_color		*color;
}	t_vars;

enum e_plan_2d
{
	COLONE,
	LINE,
};

typedef struct s_plan_2d
{
	int	x;
	int	y;
}	t_plan_2d;

typedef struct s_plan_3d
{
	int	x;
	int	y;
	int	z;
}	t_plan_3d;

//vars
t_vars	*ft_init_vars(t_vars *vars); //vars.c
void	ft_free_vars(t_vars *vars); //vars.c

//parsing
void	*ft_main_parsing(int fd, t_vars *vars); //parsing.c
void	*ft_check_parsing(char *line); //check_parsing.c

//window
int		window_init(t_vars *vars); //window.c
int		key_press(int keycode, t_vars *vars); //window.c
int		close_window(t_vars *vars); //window.c

//trace
void	ft_trace_grid(t_vars *vars);

#endif