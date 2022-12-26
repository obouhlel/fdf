/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:57:58 by obouhlel          #+#    #+#             */
/*   Updated: 2022/12/26 20:01:56 by obouhlel         ###   ########.fr       */
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

# define OK (void *)1

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

//structure mlx
typedef struct s_info
{
	void		*mlx;
	void		*win;
}	t_info;

typedef struct s_line
{
	int	x_1;
	int	x_2;
	int	y_1;
	int	y_2;
}	t_line;

//parsing
void	*ft_main_parsing(int fd);

//trace a line
void	ft_put_line(t_line line, t_info info);

//window
int		window_init(t_info info);
int		key_press(int keycode, t_info *info);
int		close_window(t_info *info);

#endif