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

// Nueva funcion auxiliar: Devuelve 1 si el jugador cabe ahi, 0 si choca
static int is_valid_pos(t_map *data, double x, double y)
{
    double margin = 0.4; // El radio de tu jugador

    // Comprobamos las 4 esquinas de nuestra caja de colision (Hitbox)
    if (data->map[(int)(y - margin)][(int)(x - margin)] != '0')
        return (0);
    if (data->map[(int)(y - margin)][(int)(x + margin)] != '0')
        return (0);
    if (data->map[(int)(y + margin)][(int)(x - margin)] != '0')
        return (0);
    if (data->map[(int)(y + margin)][(int)(x + margin)] != '0')
        return (0);
        
    return (1); // Las 4 esquinas estan libres, puedes pasar!
}

// Tu funcion de movimiento ahora queda super limpia y a prueba de balas
void move_player(t_map *data, double move_x, double move_y)
{
    // 1. Intentamos movernos en el eje X
    if (is_valid_pos(data, data->player.pos_x + move_x, data->player.pos_y))
        data->player.pos_x += move_x;
        
    // 2. Intentamos movernos en el eje Y
    if (is_valid_pos(data, data->player.pos_x, data->player.pos_y + move_y))
        data->player.pos_y += move_y;
}

//2. Aplica la matriz de rotacion a los vectores de direccion y de plano
// Ahora recibe directamente la velocidad (positiva o negativa)
void rotate_player(t_map *data, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	// ELIMINAMOS la linea de: rot_speed = 0.1 * rot_dir;
    
	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	
	// Rotar el vector de direccion
	data->player.dir_x = data->player.dir_x * cos(rot_speed) - data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed) + data->player.dir_y * cos(rot_speed);
	
	// Rotar el plano de camara
	data->player.plane_x = data->player.plane_x * cos(rot_speed) - data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y * cos(rot_speed);
}
