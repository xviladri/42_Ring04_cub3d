/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:53:08 by xviladri          #+#    #+#             */
/*   Updated: 2026/02/28 17:56:30 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H 
# define CUB3D_H

//# <biblioteca.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

//keyboard
# define ON_KEYPRESS 2
# define ON_DESTROY 17
# define ON_KEYRELEASE 3
# define ESC 65307

# define K_LEFT 65361
# define K_RIGHT 65363

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

# define WIDTH	1080
# define HEIGHT	1020

typedef struct s_img_d
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		size_l;
}	t_img_d;

typedef struct s_player
{
	double	speed;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}					t_player;

typedef struct s_cardinal
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}					t_cardinal;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_raycast;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	rotateleft;
	int	rotateright;
}	t_keys;

typedef struct s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	t_keys			keys;
	int				floor_color;
	int				floor_exist;
	int				ceiling_exist;
	int				ceiling_color;
	int				map_started;
	t_player		player;
	t_img_d			*imgs;
	t_cardinal		cardinal;
	unsigned int	map_width;
	unsigned int	map_height;
}	t_map;
