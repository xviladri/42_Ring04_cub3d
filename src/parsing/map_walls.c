/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 10:39:29 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/14 12:04:47 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// -- Revisa las 8 direcciones (Cruz y Diagonales) alrededor de un '0' -- //
static void	check_surroundings(t_map *data, int x, int y)
{
	if (x == 0 || y == 0 || x == (int)data->map_width - 1
		|| y == (int)data->map_height - 1)
		free_and_exit(data, "Error\nOpen map: '0' on the edge");
	if (data->map[y - 1][x] == ' ' || data->map[y + 1][x] == ' '
		|| data->map[y][x - 1] == ' ' || data->map[y][x + 1] == ' ')
		free_and_exit(data, "Error\nOpen map: '0' touches the void");
	if (data->map[y - 1][x - 1] == ' ' || data->map[y - 1][x + 1] == ' '
		|| data->map[y + 1][x - 1] == ' ' || data->map[y + 1][x + 1] == ' ')
		free_and_exit(data, "Error\nOpen map: Diagonal leak detected");
}

// Escanea toda la matriz buscando '0' vulnerables -- //
void	validate_walls(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < (int)data->map_height)
	{
		x = 0;
		while (x < (int)data->map_width)
		{
			if (data->map[y][x] == '0')
				check_surroundings(data, x, y);
			x++;
		}
		y++;
	}
}
