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

//1. Avanza o retrocede comprobando que la casilla de destino sea un '0'
void	move_player(t_map *data, double move_x, double move_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(data->player.pos_x + move_x);
	map_y = (int)(data->player.pos_y + move_y);
	
	// Colision en el eje X
	if (data->map[(int)data->player.pos_y][map_x] == '0')
		data->player.pos_x += move_x;
	// Colision en el eje Y
	if (data->map[map_y][(int)data->player.pos_x] == '0')
		data->player.pos_y += move_y;
}

//2. Aplica la matriz de rotacion a los vectores de direccion y de plano
void	rotate_player(t_map *data, double rot_dir)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = 0.1 * rot_dir;/* 0.1 radianes de velocidad de giro */
	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	
	// Rotar el vector de direccion
	data->player.dir_x = data->player.dir_x * cos(rot_speed) 
		- data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed) 
		+ data->player.dir_y * cos(rot_speed);
		
	// Rotar el plano de la camara (FOV)
	data->player.plane_x = data->player.plane_x * cos(rot_speed) 
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) 
		+ data->player.plane_y * cos(rot_speed);
}
