/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:16:12 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:34:52 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	apply_walk(t_map *data, double *move_x, double *move_y, double spd)
{
	if (data->keys.w)
	{
		*move_x += data->player.dir_x * spd;
		*move_y += data->player.dir_y * spd;
	}
	if (data->keys.s)
	{
		*move_x -= data->player.dir_x * spd;
		*move_y -= data->player.dir_y * spd;
	}
	if (data->keys.a)
	{
		*move_x += data->player.dir_y * spd;
		*move_y -= data->player.dir_x * spd;
	}
	if (data->keys.d)
	{
		*move_x -= data->player.dir_y * spd;
		*move_y += data->player.dir_x * spd;
	}
}

static void	apply_movement(t_map *data)
{
	double	move_x;
	double	move_y;

	move_x = 0.0;
	move_y = 0.0;
	apply_walk(data, &move_x, &move_y, 0.05);
	if (move_x != 0.0 || move_y != 0.0)
		move_player(data, move_x, move_y);
	if (data->keys.rotateright)
		rotate_player(data, 0.03);
	if (data->keys.rotateleft)
		rotate_player(data, -0.03);
}

void	render_frame(t_map *data)
{
	render_background(data);
	render_walls(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->imgs->img_ptr, 0, 0);
}

static int	game_loop(t_map *data)
{
	apply_movement(data);
	render_frame(data);
	return (0);
}

void	init_graphics(t_map *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_and_exit(data, "Error starting MiniLibX");
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!data->win_ptr)
		free_and_exit(data, "Error creating window");
	init_image(data);
	init_textures(data);
	mlx_hook(data->win_ptr, ON_KEYPRESS, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, ON_KEYRELEASE, 1L << 1, key_release, data);
	mlx_hook(data->win_ptr, 10, 1L << 21, focus_out, data);
	mlx_hook(data->win_ptr, 8, 1L << 5, focus_out, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, close_window, data);
	mlx_loop_hook(data->mlx_ptr, game_loop, data);
	mlx_loop(data->mlx_ptr);
}
