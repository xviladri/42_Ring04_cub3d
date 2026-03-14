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

static void	init_ew(t_map *data, char dir)
{
	if (dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
}

static void	init_player_dir(t_map *data, char dir)
{
	if (dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else
		init_ew(data, dir);
}

// Guarda la posicion del jugador y comprueba que no haya mas de uno
void	save_player_pos(t_map *data, int x, int y, int *player_count)
{
	char	dir;

	(*player_count)++;
	if (*player_count > 1)
		free_and_exit(data, "Error: There is more than one player on the map");
	data->player.pos_x = (double)x + 0.5;
	data->player.pos_y = (double)y + 0.5;
	dir = data->map[y][x];
	init_player_dir(data, dir);
	data->map[y][x] = '0';
}

static void	check_map_char(t_map *data, int x, int y, int *player_count)
{
	char	c;

	c = data->map[y][x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		save_player_pos(data, x, y, player_count);
	else if (c != '0' && c != '1' && c != ' ' && c != '\t')
		free_and_exit(data, "Error: Invalid character on the map");
}

// Recorre todo el mapa validando caracteres y buscando al jugador
void	check_map_elements(t_map *data)
{
	int	x;
	int	y;
	int	player_count;

	y = 0;
	player_count = 0;
	if (!data->map || !data->map[0])
		free_and_exit(data, "Error: The map is empty or does not exist");
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
		free_and_exit(data, "Error: There are no players on the map");
}
