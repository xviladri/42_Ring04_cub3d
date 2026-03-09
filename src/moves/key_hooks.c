/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:23:56 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:24:50 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Escucha el teclado, mueve al jugador y repinta la pantalla
int	key_press(int keycode, t_map *data)
{
	double	speed;

	speed = 0.2; /*Velocidad al caminar */
	if (keycode == ESC)
		close_window(data);
	else if (keycode == KEY_W)
		move_player(data, data->player.dir_x * speed, data->player.dir_y * speed);
	else if (keycode == KEY_S)
		move_player(data, -data->player.dir_x * speed, -data->player.dir_y * speed);
	else if (keycode == KEY_A)
		move_player(data, data->player.dir_y * speed, -data->player.dir_x * speed);
	else if (keycode == KEY_D)
		move_player(data, -data->player.dir_y * speed, data->player.dir_x * speed);
	else if (keycode == KEY_LEFT)
		rotate_player(data, -1);
	else if (keycode == KEY_RIGHT)
		rotate_player(data, 1);
	// IMPORTANT: Tras movernos, renderizamos el frame nuevo para ver el cambio
	render_frame(data);
	return (0);
}
