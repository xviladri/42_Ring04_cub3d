/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:18:02 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/08 13:44:37 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Avanza el puntero saltando los espacios en blanco iniciales
int	skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

//Identifica si la linea es de textura o de color
void	identify_element(char *line, int i, t_map *data)
{
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		save_texture(&data->cardinal.no, &line[i + 3], data);
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		save_texture(&data->cardinal.so, &line[i + 3], data);
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		save_texture(&data->cardinal.we, &line[i + 3], data);
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		save_texture(&data->cardinal.ea, &line[i + 3], data);
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		save_color(&data->floor_color, &line[i + 2], data, 1);
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		save_color(&data->ceiling_color, &line[i + 2], data, 0);
	else
		free_and_exit(data, "Elemento desconocido en el archivo .cub");
}

//Funcion principal que clasifica la linea leida
void	process_line(char *line, t_map *data)
{
	int	i;

	i = skip_spaces(line);
	/* Si la linea esta vacia (solo tenia espacios o el salto de linea) */
	if (line[i] == '\n' || line[i] == '\0')
		return ;
	/* Si es el inicio del mapa (empieza por 1 o 0) */
	if (line[i] == '1' || line[i] == '0')
	{
		data->map_started = 1;
		add_line_to_map(data, line);
	}
	/* Si el mapa ya habia empezado, todo lo demas debe ser mapa */
	else if (data->map_started == 1)
	{
		free_and_exit(data, "Linea invalida despues de empezar el mapa");
	}
	/* Si no es mapa ni esta vacia, debe ser un identificador (NO, SO, F...) */
	else
	{
		identify_element(line, i, data);
	}
}

// Guarda la ruta de la textura eliminando espacios y saltos de linea */
void	save_texture(char **dest, char *line, t_map *data)
{
	if (*dest != NULL)
		free_and_exit(data, "Textura duplicada en el archivo .cub");
	*dest = ft_strtrim(line, " \n\t");
	if (!*dest)
		free_and_exit(data, "Error de malloc al guardar la textura");
}
