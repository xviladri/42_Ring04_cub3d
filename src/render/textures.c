/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:32:53 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:45:17 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//Carga un archivo XPM individual y extrae su direccion de memoria
static void	load_single_texture(t_map *data, t_tex *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&tex->width, &tex->height);
	if (!tex->img_ptr)
	{
		printf("Error cargando textura: %s\n", path);
		free_and_exit(data, "Error al cargar archivo .xpm");
	}
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->line_len, &tex->endian);
}

// Funcion publica que carga las 4 texturas usando las rutas del parsing
void	init_textures(t_map *data)
{
	load_single_texture(data, &data->tex_n, data->cardinal.no);
	load_single_texture(data, &data->tex_s, data->cardinal.so);
	load_single_texture(data, &data->tex_e, data->cardinal.ea);
	load_single_texture(data, &data->tex_w, data->cardinal.we);
}
