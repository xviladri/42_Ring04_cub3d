/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:04:07 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 18:01:29 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Añade una nueva linea al array bidimensional data->map
void	add_line_to_map(t_map *data, char *line)
{
	char	**new_map;
	int		i;

	i = 0;
	while (data->map && data->map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		free_and_exit(data, "Error de malloc al guardar el mapa");
	i = 0;
	while (data->map && data->map[i])
	{
		new_map[i] = data->map[i];
		i++;
	}
	new_map[i] = ft_strtrim(line, "\n");
	new_map[i + 1] = NULL;
	if (data->map)
		free(data->map);
	data->map = new_map;
}

// Calcula el ancho y alto maximo del mapa y los guarda en la struct
static void	get_map_dimensions(t_map *data)
{
	int	i;
	int	len;

	i = 0;
	data->map_width = 0;
	while (data->map && data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len > (int)data->map_width)
			data->map_width = len;
		i++;
	}
	data->map_height = i;
}

// Funcion auxiliar para rellenar una sola linea con espacios
static void	pad_row(t_map *data, int y)
{
	char	*new_row;
	int		x;

	new_row = malloc(data->map_width + 1);
	if (!new_row)
		free_and_exit(data, "Error de malloc al cuadrar el mapa");
	x = 0;
	while (data->map[y][x])
	{
		new_row[x] = data->map[y][x];
		x++;
	}
	while (x < (int)data->map_width)
		new_row[x++] = ' ';
	new_row[x] = '\0';
	free(data->map[y]);
	data->map[y] = new_row;
}

// Convierte el mapa en un rectangulo perfecto rellenando los huecos (en el caso que le pasemos el mapa descuadrado)
void	pad_map(t_map *data)
{
	int	y;

	get_map_dimensions(data);
	y = 0;
	while (data->map && data->map[y])
	{
		if ((int)ft_strlen(data->map[y]) < (int)data->map_width)
			pad_row(data, y);
		y++;
	}
}
