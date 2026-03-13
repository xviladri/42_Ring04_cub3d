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

int focus_out(t_map *data)
{
	data->keys.w = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.rotateleft = 0;
	data->keys.rotateright = 0;
	return (0);
}

// Escucha el teclado, mueve al jugador y repinta la pantalla
int key_press(int keycode, t_map *data)
{
    if (keycode == ESC)
        close_window(data);
    else if (keycode == KEY_W)
        data->keys.w = 1;
    else if (keycode == KEY_S)
        data->keys.s = 1;
    else if (keycode == KEY_A)
        data->keys.a = 1;
    else if (keycode == KEY_D)
        data->keys.d = 1;
    else if (keycode == KEY_LEFT)
        data->keys.rotateleft = 1;
    else if (keycode == KEY_RIGHT)
        data->keys.rotateright = 1;
    return (0);
}

int key_release(int keycode, t_map *data)
{
    if (keycode == KEY_W)
        data->keys.w = 0;
    else if (keycode == KEY_S)
        data->keys.s = 0;
    else if (keycode == KEY_A)
        data->keys.a = 0;
    else if (keycode == KEY_D)
        data->keys.d = 0;
    else if (keycode == KEY_LEFT)
        data->keys.rotateleft = 0;
    else if (keycode == KEY_RIGHT)
        data->keys.rotateright = 0;
    return (0);
}
