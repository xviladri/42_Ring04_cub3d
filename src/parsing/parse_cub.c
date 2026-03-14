/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:46:42 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/08 13:44:49 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_cub_file(char *file_path, t_map *data)
{
	char	*line;

	data->fd = open(file_path, O_RDONLY);
	if (data->fd < 0)
		free_and_exit(data, ".cub file can not be open");
	line = get_next_line(data->fd);
	while (line != NULL)
	{
		process_line(line, data);
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	printf("FILE READ AND CLOSED CORRECTLY.\n");
	if (!data->cardinal.no || !data->cardinal.so || !data->cardinal.we
		|| !data->cardinal.ea)
	{
		free_and_exit(data, "Error: Missing textures on the map");
	}
}
