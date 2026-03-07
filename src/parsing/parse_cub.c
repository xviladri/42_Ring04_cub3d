/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:46:42 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/07 18:19:42 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//ABRE EL ARCHIVO, LEE LINEA A LINEA Y CIERRA EL fd AL TERMINAR
void	parse_cub_file(char *file_path, t_map *data)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0 )
		free_and_exit(data, ".cub file can not be open");
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_line(line, data);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("ARCHIVO LEIDO Y CERRADO CORRECTAMENTE.\n");
}
