/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:16:12 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:34:52 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Dibuja techo (mitad superior) y suelo (mitad inferior) con colores planos
static void	render_background(t_map *data)
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

// Crea la imagen en memoria donde dibujaremos cada frame
static void	init_image(t_map *data)
{
	data->imgs = malloc(sizeof(t_img_d));
	if (!data->imgs)
		free_and_exit(data, "Error de malloc para la imagen");
	data->imgs->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->imgs->img_ptr)
		free_and_exit(data, "Error al crear la imagen MLX");
	data->imgs->addr = mlx_get_data_addr(data->imgs->img_ptr,
			&data->imgs->bpp, &data->imgs->line_length, &data->imgs->endian);
}

// Dibuja 1 frame completo: fondo + paredes con texturas + vuelca a pantalla
void	render_frame(t_map *data)
{
	render_background(data);
	render_walls(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->imgs->img_ptr, 0, 0);
}

// game_loop: se llama cada frame por mlx_loop_hook
// Aqui es donde actualizamos el estado y redibujamos
static int	game_loop(t_map *data)
{
	render_frame(data);
	return (0);
}

// Inicializa toda la parte grafica y arranca el bucle del juego
void	init_graphics(t_map *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_and_exit(data, "Error al iniciar MiniLibX");
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
			"cub3D del equipo STDIN OR STDOUT");
	if (!data->win_ptr)
		free_and_exit(data, "Error al crear la ventana");
	init_image(data);
	init_textures(data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, close_window, data);
	mlx_hook(data->win_ptr, ON_KEYPRESS, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx_ptr, game_loop, data);
	mlx_loop(data->mlx_ptr);
}
