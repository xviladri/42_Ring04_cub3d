/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:24:02 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/08 13:45:10 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Guarda la posicion del jugador y comprueba que no haya mas de uno
void	save_player_pos(t_map *data, int x, int y, int *player_count)
{
	(*player_count)++;
	if (*player_count > 1)
		free_and_exit(data, "Error: Hay mas de un jugador en el mapa");
	data->player.pos_x = (double)x + 0.5;
	data->player.pos_y = (double)y + 0.5;
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
