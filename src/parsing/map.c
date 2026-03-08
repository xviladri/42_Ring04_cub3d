/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:04:07 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/08 13:44:26 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Añade una nueva linea al array bidimensional data->map */
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
