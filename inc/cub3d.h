/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:53:08 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:33:30 by xviladri         ###   ########.fr       */
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
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"

//keyboard
# define ON_KEYPRESS 2
# define ON_DESTROY 17
# define ON_KEYRELEASE 3
# define ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
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

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	rotateleft;
	int	rotateright;
}	t_keys;

//AYOUB: Estructura para guardar los datos de una textura .xpm
typedef struct s_tex
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_tex;

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
	t_tex	tex_n;
	t_tex	tex_s;
	t_tex	tex_e;
	t_tex	tex_w;
}	t_map;

//ANYADIMOS LAS FUNCIONES AQUI: ponemos el archivo donde se encuentran
//src: close_program.c
void		free_and_exit(t_map *data, char *error_msg);
int			close_window(t_map *data);
//parsing: parse_cub.c
void		parse_cub_file(char *file_path, t_map *data);
//parsing: map_textures.c
int			skip_spaces(char *line);
void		identify_element(char *line, int i, t_map *data);
void		process_line(char *line, t_map *data);
void		save_texture(char **dest, char *line, t_map *data);
//parsing: parse_colors.c
void		free_matrix(char **matrix);
int			is_valid_number(char *str);
int			extract_color(char *line, t_map *data);
void		save_color(int *dest, char *line, t_map *data, int is_floor);
//parsing: map.c
void		add_line_to_map(t_map *data, char *line);
void		pad_map(t_map *data);
//parsing: map_checks.c
void		save_player_pos(t_map *data, int x, int y, int *player_count);
void		check_map_elements(t_map *data);
//parsing: flood_fill.c
void		check_map_closed(t_map *data);
//render: render.c
void		init_graphics(t_map *data);
void		render_frame(t_map *data);
//render: render_utils.c
void		put_pixel_to_image(t_img_d *img, int x, int y, int color);
//render: map.c
void		render_walls(t_map *data);
void		init_textures(t_map *data);
//utils: ray_map.c
void		init_ray(t_map *data, t_ray *ray, int x);
void		perform_dda(t_map *data, t_ray *ray);
//moves: player_move.c
void		move_player(t_map *data, double move_x, double move_y);
void		rotate_player(t_map *data, double rot_dir);
//moves: key_hooks.c:
int			key_press(int keycode, t_map *data);
#endif
