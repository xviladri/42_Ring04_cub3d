/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:18:02 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/07 18:22:45 by xviladri         ###   ########.fr       */
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
		printf("Detectada textura NORTE: %s", &line[i + 3]);
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		printf("Detectada textura SUR: %s", &line[i + 3]);
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		printf("Detectada textura OESTE: %s", &line[i + 3]);
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		printf("Detectada textura ESTE: %s", &line[i + 3]);
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		printf("Detectado color SUELO: %s", &line[i + 2]);
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		printf("Detectado color TECHO: %s", &line[i + 2]);
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
		printf("Detectada linea de MAPA: %s", line);
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
