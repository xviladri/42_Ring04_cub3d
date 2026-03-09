/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:16:12 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 18:33:57 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Dibuja la mitad superior (Techo-celing) y la mitad inferior (Suelo-floor)
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

// Inicia la ventana, crea la memoria para el "dibujo" y activa los hooks definidos en el close_window.c
void	init_graphics(t_map *data)
{
	//1. Iniciar conexión
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_and_exit(data, "Error al iniciar MiniLibX");
	//2. Crear ventana
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D del equipo STDIN OR STDOUT");
	if (!data->win_ptr)
		free_and_exit(data, "Error al crear la ventana");
	//3. Crea la memoria de la imagen (la base para hacer el juego) (Image Buffer)
	data->imgs = malloc(sizeof(t_img_d));
	if (!data->imgs)
		free_and_exit(data, "Error de malloc para la imagen");
	data->imgs->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->imgs->img_ptr)
		free_and_exit(data, "Error al crear la imagen MLX");
	data->imgs->addr = mlx_get_data_addr(data->imgs->img_ptr,
			&data->imgs->bpp, &data->imgs->line_length, &data->imgs->endian);
	//4. Pintamos el fondo en la memoria
	render_background(data);
	//5. Volcamos la memoria en la ventana para que el usuario lo vea
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->imgs->img_ptr, 0, 0);
	//6. Conectar el teclado y la cruz roja a nuestras funciones
	mlx_hook(data->win_ptr, ON_DESTROY, 0, close_window, data);
	mlx_hook(data->win_ptr, ON_KEYPRESS, 1L << 0, key_press, data);
	// 5. Entrar en el bucle infinito del juego
	printf("Motor 3D ON. Pulsa ESC para salir.\n");
	mlx_loop(data->mlx_ptr);
}
