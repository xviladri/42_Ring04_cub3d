#include "../inc/cub3d.h"

// Se llama cuando el usuario PULSA una tecla
// Marca la tecla como activa en la struct keys (para movimiento suave)
int	key_press(int keycode, t_map *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	if (keycode == KEY_W)
		data->keys.w = 1;
	if (keycode == KEY_S)
		data->keys.s = 1;
	if (keycode == KEY_A)
		data->keys.a = 1;
	if (keycode == KEY_D)
		data->keys.d = 1;
	if (keycode == K_LEFT)
		data->keys.rotateleft = 1;
	if (keycode == K_RIGHT)
		data->keys.rotateright = 1;
	return (0);
}

// Se llama cuando el usuario SUELTA una tecla
// Desmarca la tecla (el jugador para de moverse)
int	key_release(int keycode, t_map *data)
{
	if (keycode == KEY_W)
		data->keys.w = 0;
	if (keycode == KEY_S)
		data->keys.s = 0;
	if (keycode == KEY_A)
		data->keys.a = 0;
	if (keycode == KEY_D)
		data->keys.d = 0;
	if (keycode == K_LEFT)
		data->keys.rotateleft = 0;
	if (keycode == K_RIGHT)
		data->keys.rotateright = 0;
	return (0);


}
