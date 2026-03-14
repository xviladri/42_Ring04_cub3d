/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:18:02 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 17:50:37 by xviladri         ###   ########.fr       */
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
		free_and_exit(data, "Unknown element in the .cub file");
}

// Funcion auxiliar para process_line
static void	handle_map_content(char *line, int i, t_map *data)
{
	if (line[i] == '1' || line[i] == '0')
	{
		if (data->map_started == 2)
		{
			free(line);
			free_and_exit(data, "Error: Empty line on the map");
		}
		data->map_started = 1;
		add_line_to_map(data, line);
	}
	else if (data->map_started >= 1)
	{
		free(line);
		free_and_exit(data, "Error: Invalid line on the map");
	}
	else
		identify_element(line, i, data);
}

// Funcion principal que clasifica la linea leida
void	process_line(char *line, t_map *data)
{
	int	i;

	i = skip_spaces(line);
	if (line[i] == '\n' || line[i] == '\0')
	{
		if (data->map_started == 1)
			data->map_started = 2;
		return ;
	}
	handle_map_content(line, i, data);
}

// Guarda la ruta de la textura y comprueba que no hay basura detras
void	save_texture(char **dest, char *line, t_map *data)
{
	int	i;
	int	start;

	if (*dest != NULL)
		free_and_exit(data, "Duplicate texture in the .cub file");
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	start = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		i++;
	*dest = ft_substr(line, start, i - start);
	if (!*dest)
		free_and_exit(data, "Error: malloc error saving texture");
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\n' && line[i] != '\0')
		free_and_exit(data, "Error: Trash after the texture path");
}
