/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:21:24 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:22:31 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_valid_pos(t_map *data, double x, double y)
{
	double	margin;

	margin = 0.4;
	if (data->map[(int)(y - margin)][(int)(x - margin)] != '0')
		return (0);
	if (data->map[(int)(y - margin)][(int)(x + margin)] != '0')
		return (0);
	if (data->map[(int)(y + margin)][(int)(x - margin)] != '0')
		return (0);
	if (data->map[(int)(y + margin)][(int)(x + margin)] != '0')
		return (0);
	return (1);
}

void	move_player(t_map *data, double move_x, double move_y)
{
	if (is_valid_pos(data, data->player.pos_x + move_x, data->player.pos_y))
		data->player.pos_x += move_x;
	if (is_valid_pos(data, data->player.pos_x, data->player.pos_y + move_y))
		data->player.pos_y += move_y;
}

void	rotate_player(t_map *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(rot_speed)
		- data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed) + data->player.dir_y
		* cos(rot_speed);
	data->player.plane_x = data->player.plane_x * cos(rot_speed)
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y
		* cos(rot_speed);
}
