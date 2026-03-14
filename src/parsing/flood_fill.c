/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:22:30 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/08 16:32:50 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// 1. Fotocopia del mapa para no ensuciar el original
static char	**copy_map(t_map *data)
{
	char	**copy;
	int		i;

	i = 0;
	while (data->map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		free_and_exit(data, "Malloc error while copying map");
	i = 0;
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// 2. El algoritmo: Devuelve 0 si encuentra una fuga, 1 si esta cerrado
static int	flood_fill(char **map, int x, int y)
{
	if (y < 0 || !map[y] || x < 0 || x >= (int)ft_strlen(map[y])
		|| map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	map[y][x] = 'F';
	if (!flood_fill(map, x + 1, y) || !flood_fill(map, x - 1, y)
		|| !flood_fill(map, x, y + 1) || !flood_fill(map, x, y - 1))
		return (0);
	return (1);
}

// 3. Funcion principal de validacion
void	check_map_closed(t_map *data)
{
	char	**map_copy;
	int		is_closed;
	int		start_x;
	int		start_y;

	map_copy = copy_map(data);
	start_x = (int)data->player.pos_x;
	start_y = (int)data->player.pos_y;
	is_closed = flood_fill(map_copy, start_x, start_y);
	free_matrix(map_copy);
	if (!is_closed)
		free_and_exit(data, "Error: The map is not enclosed by walls");
}
