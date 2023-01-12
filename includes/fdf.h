/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:58:41 by obouhlel          #+#    #+#             */
/*   Updated: 2023/01/12 14:56:16 by obouhlel         ###   ########.fr       */
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
//need to delete after
# include <stdio.h>

//======================RETURN=========================//
# define SUCCESS		(void *)1
# define FAIL			(void *)0
# define START			(void *)1

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
# define NOEVENTMASK		0b0
# define KEYPRESSMASK		0b1
# define KEYRELEASEMASK		0b10

//========================KEY==========================//
# define ESCAPE	65307
# define LEFT	65361
# define RIGHT	65363
# define UP		65362
# define DOWN	65364
# define PGUP	65365
# define PGDOWN	65366

//========================PLAN=========================//

enum e_point
{
	X,
	Y,
};

typedef struct s_line
{
	int				start[2];
	int				stop[2];
	unsigned int	color;
}	t_line;

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_map;

typedef struct s_proj
{
	float	x;
	float	y;
}	t_proj;

typedef struct s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}	t_pixel;

//========================LST============================//
typedef struct s_list
{
	t_map			*map;
	t_proj			*proj;
	t_pixel			*pixel;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

t_list	*ft_lst_new(t_map *map, t_proj *proj, t_pixel *pixel);
t_map	*ft_new_map(int x, int y, int z, int color);
t_proj	*ft_new_proj(float x, float y);
t_pixel	*ft_new_pixel(int x, int y, int color);
t_list	*ft_lst_last(t_list *lst);
void	ft_lst_add_back(t_list **lst, t_list *new);
void	ft_lst_print(t_list *lst);
void	ft_lst_clear(t_list *lst);

//========================VARS============================//
typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
	t_list			*lst;
	int				origin[2];
	int				x_max;
	int				y_max;
	int				dist_point;
}	t_vars;

//file vars.c
t_vars	*ft_init_vars(t_vars *vars);
void	ft_free_vars(t_vars *vars);

//======================PARSING============================//
//file parsing.c
void	*ft_main_parsing(int fd, t_vars *vars);
//check_parsing.c
void	*ft_check_parsing(char *line);

//=======================WINDOW============================//
//file Window.c
int		window_init(t_vars *vars);
int		keyboard(int keycode, t_vars *vars);
void	put_pixel(t_vars *vars, int x, int y, int color);
int		close_window(t_vars *vars);

//=======================PROJECTION=======================//
void	*ft_main_projection(t_vars *vars);

//
//file find_1.c
void	ft_better_dist(t_vars *vars, int x_max, int y_max);
float	ft_find_x_min_proj(t_list *lst);
float	ft_find_x_max_proj(t_list *lst);
float	ft_find_y_min_proj(t_list *lst);
float	ft_find_y_max_proj(t_list *lst);
//file find_2.c
int		ft_find_pixel_min_x(t_list *lst);
int		ft_find_pixel_min_y(t_list *lst);
void	ft_init_line(t_line *line);
void	ft_find_next_point_x(t_list *lst, t_line *line, int point[2]);
void	ft_find_next_point_y(t_list *lst, t_line *line, int point[2]);

void	*ft_calcule_pixel(t_vars *vars, t_list *lst);
void	ft_trace_img(t_vars *vars);
void	ft_put_line(t_vars *vars, t_line line);

#endif