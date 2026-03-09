/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:24:02 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 18:40:16 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//NUEVA: Guarda los vectores del jugador y cambia su letra por un '0' en el mapa
static void	init_player_dir(t_map *data, char dir)
{
	if (dir == 'N')
	{
		data->player.dir_x = 0; data->player.dir_y = -1;
		data->player.plane_x = 0.66; data->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		data->player.dir_x = 0; data->player.dir_y = 1;
		data->player.plane_x = -0.66; data->player.plane_y = 0;
	}
	else if (dir == 'E')
	{
		data->player.dir_x = 1; data->player.dir_y = 0;
		data->player.plane_x = 0; data->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		data->player.dir_x = -1; data->player.dir_y = 0;
		data->player.plane_x = 0; data->player.plane_y = -0.66;
	}
}

// Guarda la posicion del jugador y comprueba que no haya mas de uno (NUEVO: ahora tb llama a los vectores)
void	save_player_pos(t_map *data, int x, int y, int *player_count)
{
	char	dir;

	(*player_count)++;
	if (*player_count > 1)
		free_and_exit(data, "Error: Hay mas de un jugador en el mapa");
	data->player.pos_x = (double)x + 0.5;
	data->player.pos_y = (double)y + 0.5;
	//Extraemos la direccion y la inicializamos
	dir = data->map[y][x];
	init_player_dir(data, dir);
	//IMPORTANTE: Reemplazamos la letra por un '0' para poder caminar por ahi
	data->map[y][x] = '0';
}

// Funcion auxiliar de check_map_elements para que pase la Norminette
static void	check_map_char(t_map *data, int x, int y, int *player_count)
{
	char	c;

	c = data->map[y][x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		save_player_pos(data, x, y, player_count);
	else if (c != '0' && c != '1' && c != ' ' && c != '\t')
		free_and_exit(data, "Error: Caracter invalido en el mapa");
}

// Recorre todo el mapa validando caracteres y buscando al jugador (el unico q puede existir)
void	check_map_elements(t_map *data)
{
	int	x;
	int	y;
	int	player_count;

	y = 0;
	player_count = 0;
	if (!data->map || !data->map[0])
		free_and_exit(data, "Error: El mapa esta vacio o no existe");
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			check_map_char(data, x, y, &player_count);
			x++;
		}
		y++;
	}
	if (player_count == 0)
		free_and_exit(data, "Error: No hay ningun jugador en el mapa");
}
