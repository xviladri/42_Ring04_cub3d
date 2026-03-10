#include "../inc/cub3d.h"

// Inicializa el player según la orientación que venía en el mapa (N, S, E, W)
// El "plane" es el plano de la cámara (perpendicular a la dirección)
// Afecta el FOV (campo de visión). 0.66 = ~66° de FOV
void	init_player_dir(t_map *data)
{
	if (data->player.dir == 'N')
	{
		data->player.dir_x = 0;   data->player.dir_y = -1;
		data->player.plane_x = 0.66; data->player.plane_y = 0;
	}
	else if (data->player.dir == 'S')
	{
		data->player.dir_x = 0;   data->player.dir_y = 1;
		data->player.plane_x = -0.66; data->player.plane_y = 0;
	}
	else if (data->player.dir == 'E')
	{
		data->player.dir_x = 1;   data->player.dir_y = 0;
		data->player.plane_x = 0; data->player.plane_y = 0.66;
	}
	else if (data->player.dir == 'W')
	{
		data->player.dir_x = -1;  data->player.dir_y = 0;
		data->player.plane_x = 0; data->player.plane_y = -0.66;
	}
	data->player.speed = 0.05; // velocidad de movimiento
}

// Función principal de init
void	init_mlx(t_map *data)
{
	// 1. Arrancar MiniLibX — SIEMPRE lo primero
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_and_exit(data, "Error: mlx_init() failed");

	// 2. Crear la ventana
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!data->win_ptr)
		free_and_exit(data, "Error: mlx_new_window() failed");

	// 3. Inicializar dirección del jugador
	init_player_dir(data);
}
