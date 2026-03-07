/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:43:35 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/07 18:49:59 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Libera un array bidimensional (resultado de ft_split)
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

//  Valida que el string solo tenga numeros y espacios
int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' 
			&& str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

// Extrae, valida y convierte R, G, B en un solo int
int	extract_color(char *line, t_map *data)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3] != NULL)
	{
		free_matrix(rgb);
		free_and_exit(data, "Invalid color format. Use: R,G,B");
	}
	if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1]) 
		|| !is_valid_number(rgb[2]))
		free_and_exit(data, "Invalid characters in the color");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_matrix(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		free_and_exit(data, "Colors out of the range (0-255)");
	return ((r << 16) | (g << 8) | b);
}

// Funcion principal llamada desde map_textures.c
void	save_color(int *dest, char *line, t_map *data, int is_floor)
{
	if (is_floor && data->floor_exist)
		free_and_exit(data, "Color for the floor is duplicated");
	if (!is_floor && data->ceiling_exist)
		free_and_exit(data, "Color for the ceiling is duplicated");
	*dest = extract_color(line, data);
	if (is_floor)
		data->floor_exist = 1;
	else
		data->ceiling_exist = 1;
}
