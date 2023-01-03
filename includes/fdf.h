/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:58 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/03 15:41:11 by obouhlel         ###   ########.fr       */
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

//======================RETURN=========================//
# define SUCCESS	(void *)1
# define FAIL		(void *)0

//=====================WINDOW SIZE=====================//
# define WIN_X 1200
# define WIN_Y 700

//========================EVENT========================//
enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

//========================MASK=========================//
# define NOEVENTMASK	0b0
# define KEYPRESSMASK	0b1
# define KEYRELEASEMASK	0b10

//========================KEY==========================//
# define ESCAPE	65307

//========================PLAN=========================//

/*
	For the function ft_trace_grid
	I need to calculate the line with
	the type of line, if it's column
	or line.
*/

enum e_plan_2d
{
	COLUMN,
	LINE,
};

/*
	index for tab, when I need 0 1 2,
	0 it's X
	1 it's Y
	2 it's Z
*/

enum e_point
{
	X,
	Y,
	Z,
};

/*
	line

	A --- B
*/

typedef struct s_line
{
	double	a[2];
	double	b[2];
}	t_line;

/*
	plan 2D

	A --- C
	|     |
	|     |
	B --- D
*/

typedef struct s_plan_2d
{
	int	a[2];
	int	b[2];
	int	c[2];
	int	d[2];
}	t_plan_2d;

/*
	MATRICE 3 * 1
	X (i + 1 of line)
	Y (id_line)
	Z (line[i])
	the next col
*/

typedef struct s_matrice_3D
{
	int					x;
	int					y;
	int					z;
	struct s_matrice_3D	*next;
}	t_matrice_3D;

typedef struct s_matrice_2D
{
	double				x;
	double				y;
	struct s_matrice_2D	*next;
}	t_matrice_2D;

//========================MAP============================//
typedef struct s_map
{
	int				nb_col;
	int				nb_line;
	int				id_line;
	int				*line;
	t_matrice_3D	*mat_3d;
	struct s_map	*previous_line;
	struct s_map	*next_line;
}	t_map;

//folder fdf/map
void			ft_map_add_back(t_map **map, t_map *new);
void			ft_map_add_back(t_map **map, t_map *new);
void			ft_map_clear(t_map *map);
t_map			*ft_map_last(t_map *map);
t_map			*ft_map_new(int *line, int nb_col, int id_line);
int				ft_map_size(t_map *map);
void			ft_map_init_nb_line(t_map *map);
void			ft_map_print(t_map *map);
t_matrice_3D	*ft_map_matrice(int *line, int nb_col, int id_line);

//========================COLOR==========================//
typedef struct s_color
{
	int				col;
	int				line;
	char			*hex;
	struct s_color	*next;
}	t_color;

//folder fdf/color
void			ft_color_add_back(t_color **color, t_color *new);
void			ft_color_add_back(t_color **color, t_color *new);
void			ft_color_clear(t_color *color);
t_color			*ft_color_last(t_color *color);
t_color			*ft_color_new(char *hex, int col, int line);
int				ft_color_size(t_color *color);
void			ft_color_print(t_color *color);

//========================VARS============================//
typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_matrice_2D	*mat_2d;
	t_color			*color;
}	t_vars;

//file vars.c
t_vars			*ft_init_vars(t_vars *vars);
void			ft_free_vars(t_vars *vars);

//======================PARSING============================//
//file parsing.c
void			*ft_main_parsing(int fd, t_vars *vars);
//check_parsing.c
void			*ft_check_parsing(char *line);

//=======================WINDOW============================//
//file Window.c
int				window_init(t_vars *vars);
int				key_press(int keycode, t_vars *vars);
int				close_window(t_vars *vars);

//========================TRACE============================//
//file grid.c
void			ft_trace_grid(t_vars *vars);
//file projection.c
void			ft_mat_2d_clear(t_matrice_2D *mat_2d);
void			*ft_main_projection(t_vars *vars);
//file projection_calcule.c
t_matrice_2D	*ft_calcule_projection(t_map *map, double **mp, \
double x, double y);
//file matrice_projection.c
double			**ft_matrice_projection(void);
void			ft_mp_clear(double **mp);

#endif