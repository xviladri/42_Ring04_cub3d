/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:27:06 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 18:28:24 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// 1. Ponemos 1 pixel directamente en la memoria de la imagen
void	put_pixel_to_image(t_img_d *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// 2. Dibuja techo (mitad superior) y suelo (mitad inferior)
void	render_background(t_map *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel_to_image(data->imgs, x, y, data->ceiling_color);
			else
				put_pixel_to_image(data->imgs, x, y, data->floor_color);
			x++;
		}
		y++;
	}
}

// 3. Crea la imagen en memoria donde dibujaremos cada frame
void	init_image(t_map *data)
{
	data->imgs = malloc(sizeof(t_img_d));
	if (!data->imgs)
		free_and_exit(data, "Error: malloc error for image");
	data->imgs->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->imgs->img_ptr)
		free_and_exit(data, "Error: creating MLX image");
	data->imgs->addr = mlx_get_data_addr(data->imgs->img_ptr,
			&data->imgs->bpp, &data->imgs->line_length, &data->imgs->endian);
}
